<?php include('header.php'); ?>		
		<!-- Page content -->
        <div id="content" class="col-md-12">
          








          <!-- page header -->
          <div class="pageheader">
            

            <h2><i class="fa fa-puzzle-piece" style="line-height: 48px;padding-left: 5px;"></i> 任务概况 <span></span></h2>
            

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
              <div class="col-md-10">


 				<!-- tile -->
                <section class="tile color transparent-white" id="JobList">



                  <!-- tile header -->
                  <div class="tile-header">
                    <h1><strong>任务</strong>列表</h1>
                    <div class="controls">
                      <a href="#" class="refresh"><i class="fa fa-refresh"></i></a>
                      <a href="#" class="remove"><i class="fa fa-times"></i></a>
                    </div>
                  </div>
                  <!-- /tile header -->

                  <!-- tile body -->
                  <div class="tile-body nopadding">
                    <div class="modal fade" id="modalDialog" tabindex="-1" role="dialog" aria-labelledby="modalDialogLabel" aria-hidden="true">
                      <div class="modal-dialog">
                        <div class="modal-content">
                          <div class="modal-header">
                            <button type="button" class="close" data-dismiss="modal" aria-hidden="true">Close</button>
                            <h3 class="modal-title" id="modalDialogLabel"><strong>Modal</strong> title</h3>
                          </div>
                          <div class="modal-body">
                            <p>One fine body&hellip;</p>
                          </div>
                        </div><!-- /.modal-content -->
                      </div><!-- /.modal-dialog -->
                    </div><!-- /.modal -->
                    
                    <table class="table table-striped" >
                      <thead>
                        <tr>
                          <th>#</th>
                          <th>任务名称</th>
                          <th>参数</th>
                          <th>创建时间</th>
                          <th>创建用户</th>
                          <th>状态</th>
                          <th>结果</th>
                        </tr>
                      </thead>
                      <tbody>
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
    <script>
      
	function ModelInit()
	{
		$(".table.table-striped a").click(function(){
			var id = $(this).parents("tr").find('td:first').text();
			var url = "<?php echo $config['base_url']; ?>/main/GetResult/" + id;
			$("#modalDialog .modal-body").load( url, function(responseTxt,statusTxt,xhr){
			});
		});
    }

	function JobLoad()
	{
		$.get("<?php echo $config['base_url']; ?>/main/GetJob", function(data){
			var str;
			var sta;
			$.each(data, function(i, item){
				switch(item[5])
				{
				case '0':
					sta = '<td><span class="label label-primary">Pending</span></td>';
					break;
				case '1':
					sta = '<td><span class="label label-success">Success</span></td>';
					break;
				case '2':	
					sta = '<td><span class="label label-red">Fail</span></td>';
					break;
				case '3':	
					sta = '<td><span class="label label-amethyst">Running</span></td>';
					break;
				}
				str += '<tr>';
                str += '<td>' + item[0] + '</td>';
				str += '<td>' + item[1] + '</td>';
                str += '<td>' + item[2] + '</td>';
                str += '<td>' + item[3] + '</td>';
				str += '<td>' + item[4] + '</td>';
				str += sta;
	 			str += '<td><a data-target="#modalDialog" role="button" class="btn btn-cyan" data-toggle="modal">查看</a></td>';
                str += '</tr>';
			});
			$(".table.table-striped tbody").html(str);
			ModelInit();
		},"json");
	}

	$(function(){
		$("#JobList .refresh").click(JobLoad);
		setInterval(JobLoad, 10000);
		JobLoad();
	});

    </script>
<?php include('footer.php'); ?>
