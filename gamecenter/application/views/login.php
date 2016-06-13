<!DOCTYPE html>
<html>
  <head>
    <title>Operation System</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta charset="UTF-8" />

    <link rel="icon" type="image/ico" href="http://tattek.com/minimal/assets/images/favicon.ico" />
    <!-- Bootstrap -->
    <link href="<?php echo $config['base_url']; ?>/static/assets/css/vendor/bootstrap/bootstrap.min.css" rel="stylesheet">
    <link href="http://netdna.bootstrapcdn.com/font-awesome/4.0.3/css/font-awesome.css" rel="stylesheet">
    <link rel="stylesheet" href="<?php echo $config['base_url']; ?>/static/assets/css/vendor/bootstrap-checkbox.css">

    <link href="<?php echo $config['base_url']; ?>/static/assets/css/minimal.css" rel="stylesheet">

    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
      <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
      <script src="https://oss.maxcdn.com/libs/respond.js/1.3.0/respond.min.js"></script>
    <![endif]-->
  </head>
  <body class="bg-3">
 

    <!-- Wrap all page content here -->
    <div id="wrap">
      <!-- Make page fluid -->
      <div class="row">
        <!-- Page content -->
        <div id="content" class="col-md-12 full-page login">


          <div class="inside-block">
            <img src="<?php echo $config['base_url']; ?>/static/assets/images/logo-big.png" alt class="logo">
            <h1><strong>Welcome</strong> Stranger</h1>
            <h5>Operation system</h5>

			<form id="form-signin" class="form-signin" action="<?php echo $config['base_url'] ?>/login/dologin" method="post">
              <section>
                <div class="input-group">
                  <input type="text" class="form-control" name="username" placeholder="用户名">
                  <div class="input-group-addon"><i class="fa fa-user"></i></div>
                </div>
                <div class="input-group">
                  <input type="password" class="form-control" name="password" placeholder="密码">
                  <div class="input-group-addon"><i class="fa fa-key"></i></div>
                </div>
              </section>
              <section class="controls">
                <div class="checkbox check-transparent">
                  <input type="checkbox" value="1" id="remember" checked>
                  <label for="remember">记住我</label>
                </div>
                <a href="#">忘记密码?</a>
              </section>
              <section class="log-in">
                <button class="btn btn-greensea">登陆</button>
                <span>or</span>
                <button class="btn btn-slategray">创建账号</button>
              </section>
            </form>
          </div>


        </div>
        <!-- /Page content -->  
      </div>
    </div>
    <!-- Wrap all page content end -->
  </body>
</html>
      
