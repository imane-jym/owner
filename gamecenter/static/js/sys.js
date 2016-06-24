function onFollowClick() {
	    $(".modal-backdrop").toggle();
		    $(".modal-backdrop-trans").toggle();
}
$(document).ready(function() {
	    $(".modal-backdrop").click(onFollowClick);
});
$(function() {
	$(".flexslider").flexslider();
});
function c() {
	var t = location.hash, n = t.length, r = t.substr(1), i;
	n > 0 && (r == "hot" || r == "newgame" || r == "gift" || r == "category") && (o = r);
	switch (o) {
		case"hot":
			i = $("#menu-hot .dk");
			break;
		case"newgame":
			i = $("#menu-newgame .dk");
			break;
		case"gift":
			i = $("#menu-gift .dk");
			break;
		case"category":
			i = $("#menu-category .dk")
	}
	h(o)
}

function yjuafixed(t) {
	var n = $(t).offset().top, r = function () {
		var r = $(window).scrollTop();
		r > n ? $(t).css({position: "fixed", top: 0}).addClass("isStuck") : $(t).css({
			position: "static",
		  top: n
		}).removeClass("isStuck")
	};
	r(), $(window).scroll(function () {
		r()
	})
}

function h(t) {
	$(".dk").removeClass("m-active"), yjuafixed(".index-tab");
	switch (t) {
		case"hot":
			$("#menu-hot .dk").addClass("m-active"), $(".newgame,.gift,.category").addClass("gone"), $(".hot").removeClass("gone");
			break;
		case"newgame":
			$("#menu-newgame .dk").addClass("m-active"), $(".hot,.gift,.category").addClass("gone"), $(".newgame").removeClass("gone");
			break;
		case"gift":
			$("#menu-gift .dk").addClass("m-active"), $(".hot,.newgame,.category").addClass("gone"), $(".gift").removeClass("gone");
			break;
		case"category":
			$("#menu-category .dk").addClass("m-active"), $(".hot,.newgame,.gift").addClass("gone"), $(".category").removeClass("gone");
			break;
		default:
			$("#menu-hot .dk").addClass("m-active"), $(".newgame,.gift,.category").addClass("gone"), $(".hot").removeClass("gone")
	}
}
$(document).on("click", ".dk", function () {
	o = $(this).attr("data-track");
	//			p($(this));
	h(o);
})
$(document).on("click", ".more-info", function () {
	$(this).html('加载中...');
	var t = $(this).parents('.more-info').attr("data-track"), page = $(this).parents('.more-info').attr("data-num");
	GameLoad($(this));
})

function GameLoad(target)
{
	var url = $("#home").attr('data-url');
	var channel = parseInt($("#home").attr('data-channel'));
	var more = target;
	var page = parseInt(more.attr('data-num'));
	var type = more.attr('data-track');
	switch(type)
	{
		case "hot":
			url += "/main/hotGame";
			if (channel)
				url += "/channel/" + channel;
			url += "?page=" + page;
			break;
		case "newgame":
			url += "/main/newGame";
			if (channel)
				url += "/channel/" + channel;
			url += "?page=" + page;
			break;
		case "category":
			url += "/category/categoryGame";
			if (channel)
				url += "/channel/" + channel;
			url += "?page=" + page;
			url += '&category_id=' + $("#home").attr('data-category-id');
			break;
		default:
			return;
	}
	$.get(url, function(data){
		var str = '';
		if (data.status != 0)
			return;
		switch(type)
		{
			case "hot":
				for(var i in data['data'])
				{
					var item = data['data'][i];
					var href = item['url'];
					if (href.indexOf("?"))
					{
						href += "&channel=" + channel;
					}
					else
					{
						href += "?channel=" + channel;
					}
					str += '<div class="item">';
					str += '<a class="i-info" href="' + href + '">';
					str += '<figure class="cover"><img src="' + item['icon'] + '"></figure>';
					str += '<div class="meta"><h3 class="title">' + item['title'] + '</h3>';
					str += '<div class="desc">' + item['brief'] + '</div>';
					str += '</div>';
					str += '</a>';
					str += '<a href="' + href + '">';
					str += '<div class="play-btn"><i class="icon-right"></i>开始</div>';
        		    str += '</a>';
        		    str += '</div>';
				}
				$("#hot-game-list").append(str);
				break;
			case "newgame":
				for(var i in data['data'])
				{
					var item = data['data'][i];
					var href = item['url'];
					if (href.indexOf("?"))
					{
						href += "&channel=" + channel;
					}
					else
					{
						href += "?channel=" + channel;
					}
					str += '<div class="item">';
					str += '<a class="i-info" href="' + href + '">';
					str += '<figure class="cover"><img src="' + item['icon'] + '"></figure>';
					str += '<div class="meta"><h3 class="title">' + item['title'] + '</h3>';
					str += '<div class="desc">' + item['brief'] + '</div>';
					str += '</div>';
					str += '</a>';
					str += '<a href="' + href + '">';
					str += '<div class="play-btn"><i class="icon-right"></i>开始</div>';
        		    str += '</a>';
        		    str += '</div>';
				}
				$("#new-game").append(str);
				break;
			case "category":
				for(var i in data['data'])
				{
					var item = data['data'][i];
					var href = item['url'];
					if (href.indexOf("?"))
					{
						href += "&channel=" + channel;
					}
					else
					{
						href += "?channel=" + channel;
					}
					str += '<div class="item">';
					str += '<a class="i-info" href="' + href + '">';
					str += '<figure class="cover"><img src="' + item['icon'] + '"></figure>';
					str += '<div class="meta"><h3 class="title">' + item['title'] + '</h3>';
					str += '<div class="desc">' + item['brief'] + '</div>';
					str += '</div>';
					str += '</a>';
					str += '<a href="' + href + '">';
					str += '<div class="play-btn"><i class="icon-right"></i>开始</div>';
        		    str += '</a>';
        		    str += '</div>';
				}
				$("#category-game-list").append(str);
				break;
			default:
				return;
		}
		more.attr('data-num', page + 1);
		target.html('点击加载更多');
		if (!data.isMore)
		{
			more.css('display', 'none');
		}
	},"json");
}

h("hot");
