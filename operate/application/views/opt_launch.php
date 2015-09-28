<?php include('header.php'); ?>		
		<!-- Page content -->
        <div id="content" class="col-md-12">
          








          <!-- page header -->
          <div class="pageheader">
            

            <h2><i class="fa fa-puzzle-piece" style="line-height: 48px;padding-left: 5px;"></i> 操作模块 <span></span></h2>
            

            <!-- <div class="breadcrumbs">
              <ol class="breadcrumb">
                <li>You are here</li>
                <li><a href="index.html">Minimal</a></li>
                <li><a href="tables.html">Tables</a></li>
                <li class="active">Bootstrap Tables</li>
              </ol>
            </div> -->


          </div>
          <!-- /page header -->
          
          




          <!-- content main container -->
          <div class="main">




            <!-- row -->
            <div class="row">




              <!-- col 6 -->
              <div class="col-md-8">


 				<!-- tile -->
                <section class="tile color transparent-white">



                  <!-- tile header -->
                  <div class="tile-header">
                    <h1><strong>自定义</strong> 工作</h1>
                    <div class="controls">
                      <a href="#" class="refresh"><i class="fa fa-refresh"></i></a>
                      <a href="#" class="remove"><i class="fa fa-times"></i></a>
                    </div>
                  </div>
                  <!-- /tile header -->

                  <!-- tile body -->
                  <div class="tile-body">
                    
				  <form class="form-horizontal" role="form" action="<?php echo $config['base_url'] ?>/OptLaunch/PostJob" method="post">
				  <input type="hidden" id="JobModelModuleId" value="<?php echo $module_id; ?>" name="JobModelModuleId">
					
                      <div class="form-group">
                        <label for="JobModelParam" class="col-sm-4 control-label">参数</label>
                        <div class="col-sm-8">
                          <input type="text" class="form-control" id="JobModelParam" name="JobModelParam">
                        </div>
                      </div>
					  <div class="form-group">
                        <label for="JobModelJobContent" class="col-sm-4 control-label">内容</label>
                        <div class="col-sm-8">
                          <input type="text" class="form-control" id="JobModelJobContent" name="JobModelJobContent">
                        </div>
                      </div>
					  <div class="form-group">
						<label class="col-sm-4 control-label">选项</label>
						<div class="col-sm-8">
						  <div class="checkbox check-transparent">
							<input type="checkbox" value="1" id="JobModelIsSave" name="JobModelIsSave">
							<label for="JobModelIsSave">是否保存模板</label>
						  </div>
						</div>
					  </div>
                      <div class="form-group form-footer footer-white">
                        <div class="col-sm-offset-4 col-sm-8">
                          <button type="submit" class="btn btn-greensea">Submit</button>
                          <button type="reset" class="btn btn-red">Reset</button>
                        </div>
                      </div>
                            
                    </form>

                  </div>
                  <!-- /tile body -->
                  
                


                </section>
                <!-- /tile -->
				
                <!-- tile -->
                <section class="tile color transparent-white">



                  <!-- tile header -->
                  <div class="tile-header">
                    <h1><strong>工作</strong> 模板</h1>
                    <div class="controls">
                      <a href="#" class="refresh"><i class="fa fa-refresh"></i></a>
                      <a href="#" class="remove"><i class="fa fa-times"></i></a>
                    </div>
                  </div>
                  <!-- /tile header -->

                  <!-- tile body -->
                  <div class="tile-body nopadding">
                    
                    <table class="table table-striped">
                      <thead>
                        <tr>
                          <th>#</th>
                          <th>模板名字</th>
                          <th>参数</th>
                          <th>操作</th>
                        </tr>
                      </thead>
                      <tbody>
<?php
foreach($job_model_arr as $val)
{
	echo "<tr>
		<td>{$val[0]}</td>
		<td>{$val[1]}</td>
		<td>{$val[2]}</td>
		<td><a href=\"{$config['base_url']}/OptLaunch/JobExec/{$val[0]}\" class=\"btn btn-red\">build</a></td>
		";
}
?>
                      </tbody>
                    </table>

                  </div>
                  <!-- /tile body -->
                  
                


                </section>
                <!-- /tile -->



              </div>
              <!-- /col 6 -->


              
            </div>
            <!-- /row -->
          


          </div>
          <!-- /content container -->
<?php include('footer.php'); ?>
