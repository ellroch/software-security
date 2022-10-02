from flask import Flask, render_template, request
from flask_sqlalchemy import SQLAlchemy
from base64 import b64encode

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///./test.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)

class User(db.Model):
    id       = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(100), nullable=False)
    password = db.Column(db.String(500), nullable=False)

def get_user_by_username(username):
    return User.query.filter_by(username=username).first() # fetches the user created for the example

@app.route('/')
def home():
    return render_template('home.html')

# you can ignore fixing this - it's included for convenience
# **********************************************************
@app.route('/dump/<username>')
def dump(username=None):
    if username:
        user = get_user_by_username(username) # search for user
        if user:                              # if user is found, show user and password info
            return render_template("dump.html", user=user)
    return render_template("dump.html")
# **********************************************************

@app.route('/login', methods=['GET', 'POST'])
def login():
    msg = None
    username = None
    if request.method == 'POST': # when the form is submitted get the user data
        username = request.form.get('username')
        password = request.form.get('password')

        # lookup user
        user = get_user_by_username(username)
        if user: # if the user exists
            if user.password == b64encode(password.encode('utf-8')):
                msg = "User logged in!"
            else:
                msg = "Invalid password"
        else:
            msg = "User not found"
    return render_template('login.html', message=msg, username=username )

if __name__ == '__main__':
    app.run("0.0.0.0") # if the script is run directly listen on all interfaces
