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
	var t = $(this).attr("data-track"), n = $(this).attr("data-num");
	switch (t) {
		case"hot":
			//					y(n);
			break;
		case"newgame":
			//					v(n);
			break;
		case"gift":
			//					m(n)
	}
})
h("hot");
