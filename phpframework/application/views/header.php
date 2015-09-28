<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>master launch</title>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link href="static/style.css" rel="stylesheet" type="text/css" />

<script type="text/javascript" src="static/js/cufon-yui.js"></script>
<script type="text/javascript" src="static/js/georgia.js"></script>
<script type="text/javascript" src="static/js/cuf_run.js"></script>

<link rel="stylesheet" href="http://code.jquery.com/ui/1.10.3/themes/smoothness/jquery-ui.css">
  <script src="http://code.jquery.com/jquery-1.9.1.js"></script>
  <script src="http://code.jquery.com/ui/1.10.3/jquery-ui.js"></script>
  <script>
  $(function() {
    $( "#from" ).datepicker({
      defaultDate: "+1w",
      changeMonth: true,
      numberOfMonths: 3,
      onClose: function( selectedDate ) {
        $( "#to" ).datepicker( "option", "minDate", selectedDate );
      },
	  dateFormat: "yy-mm-dd"
    });
    $( "#to" ).datepicker({
      defaultDate: "+1w",
      changeMonth: true,
      numberOfMonths: 3,
      onClose: function( selectedDate ) {
        $( "#from" ).datepicker( "option", "maxDate", selectedDate );
      },
	  dateFormat: "yy-mm-dd"
    });
  });
  </script>
<!-- CuFon ends -->
</head>
<body>
