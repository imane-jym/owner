<?php include('header.php'); ?>
<div class="main">

  <div class="header">
    <div class="header_resize">
      <div class="menu_nav">
        <ul>
          <li class="active"><a href="index.html">Home</a></li>
          <li><a href="support.html">Support</a></li>
          <li><a href="about.html">About Us</a></li>
          <li><a href="blog.html">Blog</a></li>
          <li><a href="contact.html">Contact Us</a></li>
        </ul>
      </div>
      <div class="clr"></div>
    </div>
  </div>

  <div class="hbg">
    <div class="logo"><h1><a href="index.html"><span>Master</span> manage system <small>For the honour</small></a></h1></div>
  </div>

  <div class="content">
    <div class="content_resize">
      <div class="mainbar">
        <div class="article">
          <h2>Upload Resource File</h2><div class="clr"></div>
<!--     <h2>Upload Resource File</h2><div class="clr"></div>
         <p>Posted by <a href="#">Owner</a> &nbsp;&bull;&nbsp; Filed under <a href="#">templates</a>, <a href="#">internet</a></p>
          <p>This is a free CSS website template by iWebsiteTemplate.com. This 
work is distributed under the Creative Commons Attribution 3.0 License, 
which means that you are free to use it for any personal or commercial purpose provided you credit me in the form of a link back to <a href="http://www.cssmoban.com/" title="模板之家">模板之家</a></p>
 		<p class="spec"><a href="#" class="rm">Read more</a> &nbsp;&bull;&nbsp; <a href="#" class="com">Comments (3)</a> &nbsp;&bull;&nbsp; <span class="date">March 16, 2018</span></p> -->
<p>
			<form enctype="multipart/form-data" action="filectrl/upload" target="_blank" method="POST">
				<!-- MAX_FILE_SIZE must precede the file input field -->
				<input type="hidden" name="MAX_FILE_SIZE" value="40000000" />
				<!-- Name of input element determines name in $_FILES array -->
				上传文件: <input class="button button-alt" name="userfile" type="file" /><br />
				<button class="button button-big" type="submit">上传</button>
			</form>
</p>
        </div>
        <div class="article">
          <h2>Server manage</h2><div class="clr"></div>
<!--
          <h2><span>Lorem Ipsum</span> Dolor Sit</h2><div class="clr"></div>
          <p>Posted by <a href="#">Owner</a> &nbsp;&bull;&nbsp; Filed under <a href="#">templates</a>, <a href="#">internet</a></p>
          <p>Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Donec libero. Suspendisse bibendum. Cras id urna. Morbi tincidunt, orci ac convallis aliquam, lectus turpis varius lorem, eu posuere nunc justo tempus leo. Donec mattis, purus nec placerat bibendum, dui pede condimentum odio, ac blandit ante orci ut diam. Cras fringilla magna. Phasellus suscipit, leo a pharetra condimentum, lorem tellus eleifend magna, eget fringilla velit magna id neque. Curabitur vel urna. In tristique orci porttitor ipsum. Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Donec libero. Suspendisse bibendum. Cras id urna. Morbi tincidunt, orci ac convallis aliquam.</p>
          <p>Aenean commodo elit ac ante dignissim iaculis sit amet non velit. Donec magna sapien, molestie sit amet faucibus sit amet, fringilla in urna. Aliquam erat volutpat. Fusce a dui est. Sed in volutpat elit. Nam odio tortor, pulvinar non scelerisque in, eleifend nec nunc. Sed pretium, massa sed dictum dapibus, nibh purus posuere magna, ac porta felis lectus ut neque. Nullam sagittis ante vitae velit facilisis lacinia. Cras vehicula lacinia ornare. Duis et cursus risus. Curabitur consectetur justo sit amet odio viverra vel iaculis odio gravida. Ut imperdiet metus nec erat.</p>
          <p class="spec"><a href="#" class="rm">Read more</a> &nbsp;&bull;&nbsp; <a href="#" class="com">Comments (7)</a> &nbsp;&bull;&nbsp; <span class="date">March 15, 2010</span></p>
-->
			<form name="input" action="serverctrl" target="_blank" method="post">
				<div>
					<?php
						for ($i = 0; $i < count($res); $i++)
						{
							echo '<strong>' . $res[$i] . '</strong><input type="radio" name="res" value="' . $res[$i] . '" /><br />';
						}
					?>
				</div>
				<div>
					<?php
						foreach($serveraddr as $key => $val)
						{
							echo '<strong>' . $val[0] . '</strong>';
						   	echo '<button class="button button-big" type="submit" name="oper" value="' . $val[1] . '" >' . "发布" . '</button>';
							echo '<button class="button button-big" type="submit" name="oper" value="' . $val[2] . '" >' . "重启" . '</button>';
							echo '<br />';
						}
					?>
				</div>
			</form> 
        </div>
		<div class="article">
		  <h2>cdkey create</h2><div class="clr"></div>
			<form name="cdkey_form" action="cdkey" target="_blank" method="post">
				<div>
					服务器选择
					<select name="server">
						<option value=""></option>
						<?php
						foreach($operate_server_addr as $key => $val)
						{
							echo '<option value="' . $key . '">' . $val[0] . '</option>';
						}
						?>
					</select><br/>
					生成者名字<input type="text" name="author" /> <br/>
					渠道号<input type="text" name="channel" /> <br />
					开始时间<input type="text" name="start_time" id="from" /> <br />
					结束时间<input type="text" name="end_time" id="to" /> <br />
					领取限制数目<input type="text" name="limit_number" /> <br />
					cdkey 批次说明<textarea rows="3" cols="100" name="content" ></textarea> <br />
					奖励配置<textarea rows="3" cols="100" name="prize" > </textarea><br />
					批量生成cdkey数目<input type="text" name="cdkey_number" /> <br />
					<button class="button button-big" type="submit">兑换码生成</button>
				</div>
			</form>
			<br />
			<h2>cdkey list get</h2><div class="clr"></div>
			<form name="cdkey_form" action="cdkey/getlist" target="_blank" method="post">
				<div>
					服务器选择
					<select name="server">
						<option value=""></option>
						<?php
						foreach($operate_server_addr as $key => $val)
						{
							echo '<option value="' . $key . '">' . $val[0] . '</option>';
						}
						?>
					</select><br/>
					批次号<input type="text" name="batch_id" /> <br/>
					<button class="button button-big" type="submit">获取列表</button>
				</div>
			</form>
		</div>
      </div>
      <div class="sidebar">
        <div class="searchform">
          <form id="formsearch" name="formsearch" method="post" action="">
            <input name="button_search" src="static/images/search_btn.gif" class="button_search" type="image" />
            <span><input name="editbox_search" class="editbox_search" id="editbox_search" maxlength="80" value="Search" type="text" /></span>
          </form>
        </div>
        <div class="gadget">
          <h2 class="star"><span>Sidebar</span> Menu</h2><div class="clr"></div>
          <ul class="sb_menu">
            <li><a href="#">Home</a></li>
            <li><a href="#">TemplateInfo</a></li>
            <li><a href="#">Style Demo</a></li>
            <li><a href="#">Blog</a></li>
            <li><a href="#">Archives</a></li>
            <li><a href="#" title="Website Templates">Web Templates</a></li>
          </ul>
        </div>
      </div>
      <div class="clr"></div>
    </div>
  </div>

  <div class="fbg">
    <div class="fbg_resize">
      <div class="col c1">
        <h2><span>Image Gallery</span></h2>
        <a href="#"><img src="static/images/pix1.jpg" width="56" height="56" alt="pix" /></a>
        <a href="#"><img src="static/images/pix2.jpg" width="56" height="56" alt="pix" /></a>
        <a href="#"><img src="static/images/pix3.jpg" width="56" height="56" alt="pix" /></a>
        <a href="#"><img src="static/images/pix4.jpg" width="56" height="56" alt="pix" /></a>
        <a href="#"><img src="static/images/pix5.jpg" width="56" height="56" alt="pix" /></a>
        <a href="#"><img src="static/images/pix6.jpg" width="56" height="56" alt="pix" /></a>
      </div>
      <div class="col c2">
        <h2><span>Lorem Ipsum</span></h2>
        <p> no use</p>
      </div>
      <div class="col c3">
        <h2><span>About</span></h2>
        <img src="static/images/white.jpg" width="56" height="56" alt="pix" />
        <p>I think this is no use<a href="#">Learn more...</a></p>
      </div>
      <div class="clr"></div>
    </div>
  </div>
  <div class="footer">
    <div class="footer_resize">
      <p class="lf">© Copyright <a href="#">MyWebSite</a>. Collect from <a href="#" target="_blank">web</a></p>
      <ul class="fmenu">
        <li class="active"><a href="index.html">Home</a></li>
        <li><a href="support.html">Support</a></li>
        <li><a href="blog.html">Blog</a></li>
        <li><a href="about.html">About Us</a></li>
        <li><a href="contact.html">Contacts</a></li>
      </ul>
      <div class="clr"></div>
    </div>
  </div>
</div>
<?php include('footer.php'); ?>

