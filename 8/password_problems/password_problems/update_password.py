#!/usr/bin/env python3
from base64 import b64encode
from app import User, db
import sys

if len(sys.argv) != 3:
    print("./update_password.py <username> <password>")
    sys.exit(1)

user = User.query.filter_by(username = sys.argv[1]).first()

if user:
    user.password = b64encode(sys.argv[2].encode('utf-8'))
    db.session.add(user)
    db.session.commit()
else:
    print("User not found")
