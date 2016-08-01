<?php include('header.php'); ?>
<div class="main">
          <h2>Upload Resource File</h2><div class="clr"></div>
<p>
			<form enctype="multipart/form-data" action="filectrl/upload" target="_blank" method="POST">
				<!-- MAX_FILE_SIZE must precede the file input field -->
				<input type="hidden" name="MAX_FILE_SIZE" value="40000000" />
				<!-- Name of input element determines name in $_FILES array -->
				上传文件: <input class="button button-alt" name="userfile" type="file" /><br />
				<button class="button button-big" type="submit">上传</button>
			</form>
</p>
          <h2>download Resource File</h2><div class="clr"></div>
<p>
			<form enctype="application/x-www-form-urlencoded" action="filectrl/download" target="_blank" method="POST">
				<!-- MAX_FILE_SIZE must precede the file input field -->
				<!-- <input type="hidden" name="MAX_FILE_SIZE" value="40000000" /> -->
				<!-- Name of input element determines name in $_FILES array -->
				下载文件: <input class="button button-alt" name="userfile"/><br />
				<button class="button button-big" type="submit">下载</button>
			</form>
</p>
</div>
<?php include('footer.php'); ?>

