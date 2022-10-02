<html>
<body>

<h1>Search for User Information</h1>
<a href="/">Home</a>

<!-- Borrowed with adjustments from https://www.w3schools.com/php/php_mysql_select.asp -->

<?php
  $server = "db";
  $user = "a2user";
  $pass = "changeme";

  // connect
  $conn = new mysqli($server, $user, $pass, "a2db");
  $sql = "SELECT * FROM users WHERE username LIKE '%" . $_POST["username"] . "%'";
  $res = $conn->query($sql);
  ?>
  <table>
  <tr>
    <th>Username</th>
    <th>Name</th>
    <th>Email</th>
  </tr>
  <?php
    while ($row = $res->fetch_assoc())
    { ?>
      <tr>
        <td><?php echo $row['username'] ?></td>
        <td><?php echo $row['first_name'] . " " . $row['last_name'] ?></td>
        <td><?php echo $row['email'] ?></td>
      </tr>
  <?php } ?>
  </table>
  <?php
    $res->free();
    $conn->close();
  ?>
</body>
</html>
