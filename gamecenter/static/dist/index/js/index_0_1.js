/*! jQuery v1.9.1 | (c) 2005, 2012 jQuery Foundation, Inc. | jquery.org/license
 //@ sourceMappingURL=jquery.min.map
 */

/*
 * jQuery FlexSlider v2.5.0
 * Copyright 2012 WooThemes
 * Contributing Author: Tyler Smith
 */

// doT.js
// 2011-2014, Laura Doktorova, https://github.com/olado/doT
// Licensed under the MIT license.

/*!
 * jQuery Cookie Plugin v1.4.1
 * https://github.com/carhartl/jquery-cookie
 *
 * Copyright 2006, 2014 Klaus Hartl
 * Released under the MIT license
 */

/**
 * @preserve FastClick: polyfill to remove click delays on browsers with touch UIs.
 *
 * @codingstandard ftlabs-jsv2
 * @copyright The Financial Times Limited [All Rights Reserved]
 * @license MIT License (see LICENSE.txt)
 */

/*! echo.js v1.7.0 | (c) 2015 @toddmotto | https://github.com/toddmotto/echo */

(function (e, t) {
    function P(e) {
        var t = e.length, n = b.type(e);
        return b.isWindow(e) ? !1 : 1 === e.nodeType && t ? !0 : "array" === n || "function" !== n && (0 === t || "number" == typeof t && t > 0 && t - 1 in e)
    }

    function B(e) {
        var t = H[e] = {};
        return b.each(e.match(E) || [], function (e, n) {
            t[n] = !0
        }), t
    }

    function I(e, n, r, i) {
        if (b.acceptData(e)) {
            var s, o, u = b.expando, a = "string" == typeof n, f = e.nodeType, c = f ? b.cache : e, h = f ? e[u] : e[u] && u;
            if (h && c[h] && (i || c[h].data) || !a || r !== t)return h || (f ? e[u] = h = l.pop() || b.guid++ : h = u), c[h] || (c[h] = {}, f || (c[h].toJSON = b.noop)), ("object" == typeof n || "function" == typeof n) && (i ? c[h] = b.extend(c[h], n) : c[h].data = b.extend(c[h].data, n)), s = c[h], i || (s.data || (s.data = {}), s = s.data), r !== t && (s[b.camelCase(n)] = r), a ? (o = s[n], null == o && (o = s[b.camelCase(n)])) : o = s, o
        }
    }

    function q(e, t, n) {
        if (b.acceptData(e)) {
            var r, i, s, o = e.nodeType, u = o ? b.cache : e, a = o ? e[b.expando] : b.expando;
            if (u[a]) {
                if (t && (s = n ? u[a] : u[a].data)) {
                    b.isArray(t) ? t = t.concat(b.map(t, b.camelCase)) : t in s ? t = [t] : (t = b.camelCase(t), t = t in s ? [t] : t.split(" "));
                    for (r = 0, i = t.length; i > r; r++)delete s[t[r]];
                    if (!(n ? U : b.isEmptyObject)(s))return
                }
                (n || (delete u[a].data, U(u[a]))) && (o ? b.cleanData([e], !0) : b.support.deleteExpando || u != u.window ? delete u[a] : u[a] = null)
            }
        }
    }

    function R(e, n, r) {
        if (r === t && 1 === e.nodeType) {
            var i = "data-" + n.replace(F, "-$1").toLowerCase();
            if (r = e.getAttribute(i), "string" == typeof r) {
                try {
                    r = "true" === r ? !0 : "false" === r ? !1 : "null" === r ? null : +r + "" === r ? +r : j.test(r) ? b.parseJSON(r) : r
                } catch (s) {
                }
                b.data(e, n, r)
            } else r = t
        }
        return r
    }

    function U(e) {
        var t;
        for (t in e)if (("data" !== t || !b.isEmptyObject(e[t])) && "toJSON" !== t)return !1;
        return !0
    }

    function it() {
        return !0
    }

    function st() {
        return !1
    }

    function ct(e, t) {
        do e = e[t]; while (e && 1 !== e.nodeType);
        return e
    }

    function ht(e, t, n) {
        if (t = t || 0, b.isFunction(t))return b.grep(e, function (e, r) {
            var i = !!t.call(e, r, e);
            return i === n
        });
        if (t.nodeType)return b.grep(e, function (e) {
            return e === t === n
        });
        if ("string" == typeof t) {
            var r = b.grep(e, function (e) {
                return 1 === e.nodeType
            });
            if (at.test(t))return b.filter(t, r, !n);
            t = b.filter(t, r)
        }
        return b.grep(e, function (e) {
            return b.inArray(e, t) >= 0 === n
        })
    }

    function pt(e) {
        var t = dt.split("|"), n = e.createDocumentFragment();
        if (n.createElement)while (t.length)n.createElement(t.pop());
        return n
    }

    function Mt(e, t) {
        return e.getElementsByTagName(t)[0] || e.appendChild(e.ownerDocument.createElement(t))
    }

    function _t(e) {
        var t = e.getAttributeNode("type");
        return e.type = (t && t.specified) + "/" + e.type, e
    }

    function Dt(e) {
        var t = Ct.exec(e.type);
        return t ? e.type = t[1] : e.removeAttribute("type"), e
    }

    function Pt(e, t) {
        var n, r = 0;
        for (; null != (n = e[r]); r++)b._data(n, "globalEval", !t || b._data(t[r], "globalEval"))
    }

    function Ht(e, t) {
        if (1 === t.nodeType && b.hasData(e)) {
            var n, r, i, s = b._data(e), o = b._data(t, s), u = s.events;
            if (u) {
                delete o.handle, o.events = {};
                for (n in u)for (r = 0, i = u[n].length; i > r; r++)b.event.add(t, n, u[n][r])
            }
            o.data && (o.data = b.extend({}, o.data))
        }
    }

    function Bt(e, t) {
        var n, r, i;
        if (1 === t.nodeType) {
            if (n = t.nodeName.toLowerCase(), !b.support.noCloneEvent && t[b.expando]) {
                i = b._data(t);
                for (r in i.events)b.removeEvent(t, r, i.handle);
                t.removeAttribute(b.expando)
            }
            "script" === n && t.text !== e.text ? (_t(t).text = e.text, Dt(t)) : "object" === n ? (t.parentNode && (t.outerHTML = e.outerHTML), b.support.html5Clone && e.innerHTML && !b.trim(t.innerHTML) && (t.innerHTML = e.innerHTML)) : "input" === n && xt.test(e.type) ? (t.defaultChecked = t.checked = e.checked, t.value !== e.value && (t.value = e.value)) : "option" === n ? t.defaultSelected = t.selected = e.defaultSelected : ("input" === n || "textarea" === n) && (t.defaultValue = e.defaultValue)
        }
    }

    function jt(e, n) {
        var r, s, o = 0, u = typeof e.getElementsByTagName !== i ? e.getElementsByTagName(n || "*") : typeof e.querySelectorAll !== i ? e.querySelectorAll(n || "*") : t;
        if (!u)for (u = [], r = e.childNodes || e; null != (s = r[o]); o++)!n || b.nodeName(s, n) ? u.push(s) : b.merge(u, jt(s, n));
        return n === t || n && b.nodeName(e, n) ? b.merge([e], u) : u
    }

    function Ft(e) {
        xt.test(e.type) && (e.defaultChecked = e.checked)
    }

    function tn(e, t) {
        if (t in e)return t;
        var n = t.charAt(0).toUpperCase() + t.slice(1), r = t, i = en.length;
        while (i--)if (t = en[i] + n, t in e)return t;
        return r
    }

    function nn(e, t) {
        return e = t || e, "none" === b.css(e, "display") || !b.contains(e.ownerDocument, e)
    }

    function rn(e, t) {
        var n, r, i, s = [], o = 0, u = e.length;
        for (; u > o; o++)r = e[o], r.style && (s[o] = b._data(r, "olddisplay"), n = r.style.display, t ? (s[o] || "none" !== n || (r.style.display = ""), "" === r.style.display && nn(r) && (s[o] = b._data(r, "olddisplay", an(r.nodeName)))) : s[o] || (i = nn(r), (n && "none" !== n || !i) && b._data(r, "olddisplay", i ? n : b.css(r, "display"))));
        for (o = 0; u > o; o++)r = e[o], r.style && (t && "none" !== r.style.display && "" !== r.style.display || (r.style.display = t ? s[o] || "" : "none"));
        return e
    }

    function sn(e, t, n) {
        var r = $t.exec(t);
        return r ? Math.max(0, r[1] - (n || 0)) + (r[2] || "px") : t
    }

    function on(e, t, n, r, i) {
        var s = n === (r ? "border" : "content") ? 4 : "width" === t ? 1 : 0, o = 0;
        for (; 4 > s; s += 2)"margin" === n && (o += b.css(e, n + Zt[s], !0, i)), r ? ("content" === n && (o -= b.css(e, "padding" + Zt[s], !0, i)), "margin" !== n && (o -= b.css(e, "border" + Zt[s] + "Width", !0, i))) : (o += b.css(e, "padding" + Zt[s], !0, i), "padding" !== n && (o += b.css(e, "border" + Zt[s] + "Width", !0, i)));
        return o
    }

    function un(e, t, n) {
        var r = !0, i = "width" === t ? e.offsetWidth : e.offsetHeight, s = qt(e), o = b.support.boxSizing && "border-box" === b.css(e, "boxSizing", !1, s);
        if (0 >= i || null == i) {
            if (i = Rt(e, t, s), (0 > i || null == i) && (i = e.style[t]), Jt.test(i))return i;
            r = o && (b.support.boxSizingReliable || i === e.style[t]), i = parseFloat(i) || 0
        }
        return i + on(e, t, n || (o ? "border" : "content"), r, s) + "px"
    }

    function an(e) {
        var t = s, n = Qt[e];
        return n || (n = fn(e, t), "none" !== n && n || (It = (It || b("<iframe frameborder='0' width='0' height='0'/>").css("cssText", "display:block !important")).appendTo(t.documentElement), t = (It[0].contentWindow || It[0].contentDocument).document, t.write("<!doctype html><html><body>"), t.close(), n = fn(e, t), It.detach()), Qt[e] = n), n
    }

    function fn(e, t) {
        var n = b(t.createElement(e)).appendTo(t.body), r = b.css(n[0], "display");
        return n.remove(), r
    }

    function vn(e, t, n, r) {
        var i;
        if (b.isArray(t))b.each(t, function (t, i) {
            n || cn.test(e) ? r(e, i) : vn(e + "[" + ("object" == typeof i ? t : "") + "]", i, n, r)
        }); else if (n || "object" !== b.type(t))r(e, t); else for (i in t)vn(e + "[" + i + "]", t[i], n, r)
    }

    function _n(e) {
        return function (t, n) {
            "string" != typeof t && (n = t, t = "*");
            var r, i = 0, s = t.toLowerCase().match(E) || [];
            if (b.isFunction(n))while (r = s[i++])"+" === r[0] ? (r = r.slice(1) || "*", (e[r] = e[r] || []).unshift(n)) : (e[r] = e[r] || []).push(n)
        }
    }

    function Dn(e, n, r, i) {
        function u(a) {
            var f;
            return s[a] = !0, b.each(e[a] || [], function (e, a) {
                var l = a(n, r, i);
                return "string" != typeof l || o || s[l] ? o ? !(f = l) : t : (n.dataTypes.unshift(l), u(l), !1)
            }), f
        }

        var s = {}, o = e === An;
        return u(n.dataTypes[0]) || !s["*"] && u("*")
    }

    function Pn(e, n) {
        var r, i, s = b.ajaxSettings.flatOptions || {};
        for (i in n)n[i] !== t && ((s[i] ? e : r || (r = {}))[i] = n[i]);
        return r && b.extend(!0, e, r), e
    }

    function Hn(e, n, r) {
        var i, s, o, u, a = e.contents, f = e.dataTypes, l = e.responseFields;
        for (u in l)u in r && (n[l[u]] = r[u]);
        while ("*" === f[0])f.shift(), s === t && (s = e.mimeType || n.getResponseHeader("Content-Type"));
        if (s)for (u in a)if (a[u] && a[u].test(s)) {
            f.unshift(u);
            break
        }
        if (f[0]in r)o = f[0]; else {
            for (u in r) {
                if (!f[0] || e.converters[u + " " + f[0]]) {
                    o = u;
                    break
                }
                i || (i = u)
            }
            o = o || i
        }
        return o ? (o !== f[0] && f.unshift(o), r[o]) : t
    }

    function Bn(e, t) {
        var n, r, i, s, o = {}, u = 0, a = e.dataTypes.slice(), f = a[0];
        if (e.dataFilter && (t = e.dataFilter(t, e.dataType)), a[1])for (i in e.converters)o[i.toLowerCase()] = e.converters[i];
        for (; r = a[++u];)if ("*" !== r) {
            if ("*" !== f && f !== r) {
                if (i = o[f + " " + r] || o["* " + r], !i)for (n in o)if (s = n.split(" "), s[1] === r && (i = o[f + " " + s[0]] || o["* " + s[0]])) {
                    i === !0 ? i = o[n] : o[n] !== !0 && (r = s[0], a.splice(u--, 0, r));
                    break
                }
                if (i !== !0)if (i && e["throws"])t = i(t); else try {
                    t = i(t)
                } catch (l) {
                    return {state: "parsererror", error: i ? l : "No conversion from " + f + " to " + r}
                }
            }
            f = r
        }
        return {state: "success", data: t}
    }

    function zn() {
        try {
            return new e.XMLHttpRequest
        } catch (t) {
        }
    }

    function Wn() {
        try {
            return new e.ActiveXObject("Microsoft.XMLHTTP")
        } catch (t) {
        }
    }

    function Yn() {
        return setTimeout(function () {
            Xn = t
        }), Xn = b.now()
    }

    function Zn(e, t) {
        b.each(t, function (t, n) {
            var r = (Gn[t] || []).concat(Gn["*"]), i = 0, s = r.length;
            for (; s > i; i++)if (r[i].call(e, t, n))return
        })
    }

    function er(e, t, n) {
        var r, i, s = 0, o = Qn.length, u = b.Deferred().always(function () {
            delete a.elem
        }), a = function () {
            if (i)return !1;
            var t = Xn || Yn(), n = Math.max(0, f.startTime + f.duration - t), r = n / f.duration || 0, s = 1 - r, o = 0, a = f.tweens.length;
            for (; a > o; o++)f.tweens[o].run(s);
            return u.notifyWith(e, [f, s, n]), 1 > s && a ? n : (u.resolveWith(e, [f]), !1)
        }, f = u.promise({
            elem: e,
            props: b.extend({}, t),
            opts: b.extend(!0, {specialEasing: {}}, n),
            originalProperties: t,
            originalOptions: n,
            startTime: Xn || Yn(),
            duration: n.duration,
            tweens: [],
            createTween: function (t, n) {
                var r = b.Tween(e, f.opts, t, n, f.opts.specialEasing[t] || f.opts.easing);
                return f.tweens.push(r), r
            },
            stop: function (t) {
                var n = 0, r = t ? f.tweens.length : 0;
                if (i)return this;
                for (i = !0; r > n; n++)f.tweens[n].run(1);
                return t ? u.resolveWith(e, [f, t]) : u.rejectWith(e, [f, t]), this
            }
        }), l = f.props;
        for (tr(l, f.opts.specialEasing); o > s; s++)if (r = Qn[s].call(f, e, l, f.opts))return r;
        return Zn(f, l), b.isFunction(f.opts.start) && f.opts.start.call(e, f), b.fx.timer(b.extend(a, {
            elem: e,
            anim: f,
            queue: f.opts.queue
        })), f.progress(f.opts.progress).done(f.opts.done, f.opts.complete).fail(f.opts.fail).always(f.opts.always)
    }

    function tr(e, t) {
        var n, r, i, s, o;
        for (i in e)if (r = b.camelCase(i), s = t[r], n = e[i], b.isArray(n) && (s = n[1], n = e[i] = n[0]), i !== r && (e[r] = n, delete e[i]), o = b.cssHooks[r], o && "expand"in o) {
            n = o.expand(n), delete e[r];
            for (i in n)i in e || (e[i] = n[i], t[i] = s)
        } else t[r] = s
    }

    function nr(e, t, n) {
        var r, i, s, o, u, a, f, l, c, h = this, p = e.style, d = {}, v = [], m = e.nodeType && nn(e);
        n.queue || (l = b._queueHooks(e, "fx"), null == l.unqueued && (l.unqueued = 0, c = l.empty.fire, l.empty.fire = function () {
            l.unqueued || c()
        }), l.unqueued++, h.always(function () {
            h.always(function () {
                l.unqueued--, b.queue(e, "fx").length || l.empty.fire()
            })
        })), 1 === e.nodeType && ("height"in t || "width"in t) && (n.overflow = [p.overflow, p.overflowX, p.overflowY], "inline" === b.css(e, "display") && "none" === b.css(e, "float") && (b.support.inlineBlockNeedsLayout && "inline" !== an(e.nodeName) ? p.zoom = 1 : p.display = "inline-block")), n.overflow && (p.overflow = "hidden", b.support.shrinkWrapBlocks || h.always(function () {
            p.overflow = n.overflow[0], p.overflowX = n.overflow[1], p.overflowY = n.overflow[2]
        }));
        for (i in t)if (o = t[i], $n.exec(o)) {
            if (delete t[i], a = a || "toggle" === o, o === (m ? "hide" : "show"))continue;
            v.push(i)
        }
        if (s = v.length) {
            u = b._data(e, "fxshow") || b._data(e, "fxshow", {}), "hidden"in u && (m = u.hidden), a && (u.hidden = !m), m ? b(e).show() : h.done(function () {
                b(e).hide()
            }), h.done(function () {
                var t;
                b._removeData(e, "fxshow");
                for (t in d)b.style(e, t, d[t])
            });
            for (i = 0; s > i; i++)r = v[i], f = h.createTween(r, m ? u[r] : 0), d[r] = u[r] || b.style(e, r), r in u || (u[r] = f.start, m && (f.end = f.start, f.start = "width" === r || "height" === r ? 1 : 0))
        }
    }

    function rr(e, t, n, r, i) {
        return new rr.prototype.init(e, t, n, r, i)
    }

    function ir(e, t) {
        var n, r = {height: e}, i = 0;
        for (t = t ? 1 : 0; 4 > i; i += 2 - t)n = Zt[i], r["margin" + n] = r["padding" + n] = e;
        return t && (r.opacity = r.width = e), r
    }

    function sr(e) {
        return b.isWindow(e) ? e : 9 === e.nodeType ? e.defaultView || e.parentWindow : !1
    }

    var n, r, i = typeof t, s = e.document, o = e.location, u = e.jQuery, a = e.$, f = {}, l = [], c = "1.9.1", h = l.concat, p = l.push, d = l.slice, v = l.indexOf, m = f.toString, g = f.hasOwnProperty, y = c.trim, b = function (e, t) {
        return new b.fn.init(e, t, r)
    }, w = /[+-]?(?:\d*\.|)\d+(?:[eE][+-]?\d+|)/.source, E = /\S+/g, S = /^[\s\uFEFF\xA0]+|[\s\uFEFF\xA0]+$/g, x = /^(?:(<[\w\W]+>)[^>]*|#([\w-]*))$/, T = /^<(\w+)\s*\/?>(?:<\/\1>|)$/, N = /^[\],:{}\s]*$/, C = /(?:^|:|,)(?:\s*\[)+/g, k = /\\(?:["\\\/bfnrt]|u[\da-fA-F]{4})/g, L = /"[^"\\\r\n]*"|true|false|null|-?(?:\d+\.|)\d+(?:[eE][+-]?\d+|)/g, A = /^-ms-/, O = /-([\da-z])/gi, M = function (e, t) {
        return t.toUpperCase()
    }, _ = function (e) {
        (s.addEventListener || "load" === e.type || "complete" === s.readyState) && (D(), b.ready())
    }, D = function () {
        s.addEventListener ? (s.removeEventListener("DOMContentLoaded", _, !1), e.removeEventListener("load", _, !1)) : (s.detachEvent("onreadystatechange", _), e.detachEvent("onload", _))
    };
    b.fn = b.prototype = {
        jquery: c, constructor: b, init: function (e, n, r) {
            var i, o;
            if (!e)return this;
            if ("string" == typeof e) {
                if (i = "<" === e.charAt(0) && ">" === e.charAt(e.length - 1) && e.length >= 3 ? [null, e, null] : x.exec(e), !i || !i[1] && n)return !n || n.jquery ? (n || r).find(e) : this.constructor(n).find(e);
                if (i[1]) {
                    if (n = n instanceof b ? n[0] : n, b.merge(this, b.parseHTML(i[1], n && n.nodeType ? n.ownerDocument || n : s, !0)), T.test(i[1]) && b.isPlainObject(n))for (i in n)b.isFunction(this[i]) ? this[i](n[i]) : this.attr(i, n[i]);
                    return this
                }
                if (o = s.getElementById(i[2]), o && o.parentNode) {
                    if (o.id !== i[2])return r.find(e);
                    this.length = 1, this[0] = o
                }
                return this.context = s, this.selector = e, this
            }
            return e.nodeType ? (this.context = this[0] = e, this.length = 1, this) : b.isFunction(e) ? r.ready(e) : (e.selector !== t && (this.selector = e.selector, this.context = e.context), b.makeArray(e, this))
        }, selector: "", length: 0, size: function () {
            return this.length
        }, toArray: function () {
            return d.call(this)
        }, get: function (e) {
            return null == e ? this.toArray() : 0 > e ? this[this.length + e] : this[e]
        }, pushStack: function (e) {
            var t = b.merge(this.constructor(), e);
            return t.prevObject = this, t.context = this.context, t
        }, each: function (e, t) {
            return b.each(this, e, t)
        }, ready: function (e) {
            return b.ready.promise().done(e), this
        }, slice: function () {
            return this.pushStack(d.apply(this, arguments))
        }, first: function () {
            return this.eq(0)
        }, last: function () {
            return this.eq(-1)
        }, eq: function (e) {
            var t = this.length, n = +e + (0 > e ? t : 0);
            return this.pushStack(n >= 0 && t > n ? [this[n]] : [])
        }, map: function (e) {
            return this.pushStack(b.map(this, function (t, n) {
                return e.call(t, n, t)
            }))
        }, end: function () {
            return this.prevObject || this.constructor(null)
        }, push: p, sort: [].sort, splice: [].splice
    }, b.fn.init.prototype = b.fn, b.extend = b.fn.extend = function () {
        var e, n, r, i, s, o, u = arguments[0] || {}, a = 1, f = arguments.length, l = !1;
        for ("boolean" == typeof u && (l = u, u = arguments[1] || {}, a = 2), "object" == typeof u || b.isFunction(u) || (u = {}), f === a && (u = this, --a); f > a; a++)if (null != (s = arguments[a]))for (i in s)e = u[i], r = s[i], u !== r && (l && r && (b.isPlainObject(r) || (n = b.isArray(r))) ? (n ? (n = !1, o = e && b.isArray(e) ? e : []) : o = e && b.isPlainObject(e) ? e : {}, u[i] = b.extend(l, o, r)) : r !== t && (u[i] = r));
        return u
    }, b.extend({
        noConflict: function (t) {
            return e.$ === b && (e.$ = a), t && e.jQuery === b && (e.jQuery = u), b
        }, isReady: !1, readyWait: 1, holdReady: function (e) {
            e ? b.readyWait++ : b.ready(!0)
        }, ready: function (e) {
            if (e === !0 ? !--b.readyWait : !b.isReady) {
                if (!s.body)return setTimeout(b.ready);
                b.isReady = !0, e !== !0 && --b.readyWait > 0 || (n.resolveWith(s, [b]), b.fn.trigger && b(s).trigger("ready").off("ready"))
            }
        }, isFunction: function (e) {
            return "function" === b.type(e)
        }, isArray: Array.isArray || function (e) {
            return "array" === b.type(e)
        }, isWindow: function (e) {
            return null != e && e == e.window
        }, isNumeric: function (e) {
            return !isNaN(parseFloat(e)) && isFinite(e)
        }, type: function (e) {
            return null == e ? e + "" : "object" == typeof e || "function" == typeof e ? f[m.call(e)] || "object" : typeof e
        }, isPlainObject: function (e) {
            if (!e || "object" !== b.type(e) || e.nodeType || b.isWindow(e))return !1;
            try {
                if (e.constructor && !g.call(e, "constructor") && !g.call(e.constructor.prototype, "isPrototypeOf"))return !1
            } catch (n) {
                return !1
            }
            var r;
            for (r in e);
            return r === t || g.call(e, r)
        }, isEmptyObject: function (e) {
            var t;
            for (t in e)return !1;
            return !0
        }, error: function (e) {
            throw Error(e)
        }, parseHTML: function (e, t, n) {
            if (!e || "string" != typeof e)return null;
            "boolean" == typeof t && (n = t, t = !1), t = t || s;
            var r = T.exec(e), i = !n && [];
            return r ? [t.createElement(r[1])] : (r = b.buildFragment([e], t, i), i && b(i).remove(), b.merge([], r.childNodes))
        }, parseJSON: function (n) {
            return e.JSON && e.JSON.parse ? e.JSON.parse(n) : null === n ? n : "string" == typeof n && (n = b.trim(n), n && N.test(n.replace(k, "@").replace(L, "]").replace(C, ""))) ? Function("return " + n)() : (b.error("Invalid JSON: " + n), t)
        }, parseXML: function (n) {
            var r, i;
            if (!n || "string" != typeof n)return null;
            try {
                e.DOMParser ? (i = new DOMParser, r = i.parseFromString(n, "text/xml")) : (r = new ActiveXObject("Microsoft.XMLDOM"), r.async = "false", r.loadXML(n))
            } catch (s) {
                r = t
            }
            return r && r.documentElement && !r.getElementsByTagName("parsererror").length || b.error("Invalid XML: " + n), r
        }, noop: function () {
        }, globalEval: function (t) {
            t && b.trim(t) && (e.execScript || function (t) {
                e.eval.call(e, t)
            })(t)
        }, camelCase: function (e) {
            return e.replace(A, "ms-").replace(O, M)
        }, nodeName: function (e, t) {
            return e.nodeName && e.nodeName.toLowerCase() === t.toLowerCase()
        }, each: function (e, t, n) {
            var r, i = 0, s = e.length, o = P(e);
            if (n) {
                if (o) {
                    for (; s > i; i++)if (r = t.apply(e[i], n), r === !1)break
                } else for (i in e)if (r = t.apply(e[i], n), r === !1)break
            } else if (o) {
                for (; s > i; i++)if (r = t.call(e[i], i, e[i]), r === !1)break
            } else for (i in e)if (r = t.call(e[i], i, e[i]), r === !1)break;
            return e
        }, trim: y && !y.call("﻿ ") ? function (e) {
            return null == e ? "" : y.call(e)
        } : function (e) {
            return null == e ? "" : (e + "").replace(S, "")
        }, makeArray: function (e, t) {
            var n = t || [];
            return null != e && (P(Object(e)) ? b.merge(n, "string" == typeof e ? [e] : e) : p.call(n, e)), n
        }, inArray: function (e, t, n) {
            var r;
            if (t) {
                if (v)return v.call(t, e, n);
                for (r = t.length, n = n ? 0 > n ? Math.max(0, r + n) : n : 0; r > n; n++)if (n in t && t[n] === e)return n
            }
            return -1
        }, merge: function (e, n) {
            var r = n.length, i = e.length, s = 0;
            if ("number" == typeof r)for (; r > s; s++)e[i++] = n[s]; else while (n[s] !== t)e[i++] = n[s++];
            return e.length = i, e
        }, grep: function (e, t, n) {
            var r, i = [], s = 0, o = e.length;
            for (n = !!n; o > s; s++)r = !!t(e[s], s), n !== r && i.push(e[s]);
            return i
        }, map: function (e, t, n) {
            var r, i = 0, s = e.length, o = P(e), u = [];
            if (o)for (; s > i; i++)r = t(e[i], i, n), null != r && (u[u.length] = r); else for (i in e)r = t(e[i], i, n), null != r && (u[u.length] = r);
            return h.apply([], u)
        }, guid: 1, proxy: function (e, n) {
            var r, i, s;
            return "string" == typeof n && (s = e[n], n = e, e = s), b.isFunction(e) ? (r = d.call(arguments, 2), i = function () {
                return e.apply(n || this, r.concat(d.call(arguments)))
            }, i.guid = e.guid = e.guid || b.guid++, i) : t
        }, access: function (e, n, r, i, s, o, u) {
            var a = 0, f = e.length, l = null == r;
            if ("object" === b.type(r)) {
                s = !0;
                for (a in r)b.access(e, n, a, r[a], !0, o, u)
            } else if (i !== t && (s = !0, b.isFunction(i) || (u = !0), l && (u ? (n.call(e, i), n = null) : (l = n, n = function (e, t, n) {
                    return l.call(b(e), n)
                })), n))for (; f > a; a++)n(e[a], r, u ? i : i.call(e[a], a, n(e[a], r)));
            return s ? e : l ? n.call(e) : f ? n(e[0], r) : o
        }, now: function () {
            return (new Date).getTime()
        }
    }), b.ready.promise = function (t) {
        if (!n)if (n = b.Deferred(), "complete" === s.readyState)setTimeout(b.ready); else if (s.addEventListener)s.addEventListener("DOMContentLoaded", _, !1), e.addEventListener("load", _, !1); else {
            s.attachEvent("onreadystatechange", _), e.attachEvent("onload", _);
            var r = !1;
            try {
                r = null == e.frameElement && s.documentElement
            } catch (i) {
            }
            r && r.doScroll && function o() {
                if (!b.isReady) {
                    try {
                        r.doScroll("left")
                    } catch (e) {
                        return setTimeout(o, 50)
                    }
                    D(), b.ready()
                }
            }()
        }
        return n.promise(t)
    }, b.each("Boolean Number String Function Array Date RegExp Object Error".split(" "), function (e, t) {
        f["[object " + t + "]"] = t.toLowerCase()
    }), r = b(s);
    var H = {};
    b.Callbacks = function (e) {
        e = "string" == typeof e ? H[e] || B(e) : b.extend({}, e);
        var n, r, i, s, o, u, a = [], f = !e.once && [], l = function (t) {
            for (r = e.memory && t, i = !0, o = u || 0, u = 0, s = a.length, n = !0; a && s > o; o++)if (a[o].apply(t[0], t[1]) === !1 && e.stopOnFalse) {
                r = !1;
                break
            }
            n = !1, a && (f ? f.length && l(f.shift()) : r ? a = [] : c.disable())
        }, c = {
            add: function () {
                if (a) {
                    var t = a.length;
                    (function i(t) {
                        b.each(t, function (t, n) {
                            var r = b.type(n);
                            "function" === r ? e.unique && c.has(n) || a.push(n) : n && n.length && "string" !== r && i(n)
                        })
                    })(arguments), n ? s = a.length : r && (u = t, l(r))
                }
                return this
            }, remove: function () {
                return a && b.each(arguments, function (e, t) {
                    var r;
                    while ((r = b.inArray(t, a, r)) > -1)a.splice(r, 1), n && (s >= r && s--, o >= r && o--)
                }), this
            }, has: function (e) {
                return e ? b.inArray(e, a) > -1 : !!a && !!a.length
            }, empty: function () {
                return a = [], this
            }, disable: function () {
                return a = f = r = t, this
            }, disabled: function () {
                return !a
            }, lock: function () {
                return f = t, r || c.disable(), this
            }, locked: function () {
                return !f
            }, fireWith: function (e, t) {
                return t = t || [], t = [e, t.slice ? t.slice() : t], !a || i && !f || (n ? f.push(t) : l(t)), this
            }, fire: function () {
                return c.fireWith(this, arguments), this
            }, fired: function () {
                return !!i
            }
        };
        return c
    }, b.extend({
        Deferred: function (e) {
            var t = [["resolve", "done", b.Callbacks("once memory"), "resolved"], ["reject", "fail", b.Callbacks("once memory"), "rejected"], ["notify", "progress", b.Callbacks("memory")]], n = "pending", r = {
                state: function () {
                    return n
                }, always: function () {
                    return i.done(arguments).fail(arguments), this
                }, then: function () {
                    var e = arguments;
                    return b.Deferred(function (n) {
                        b.each(t, function (t, s) {
                            var o = s[0], u = b.isFunction(e[t]) && e[t];
                            i[s[1]](function () {
                                var e = u && u.apply(this, arguments);
                                e && b.isFunction(e.promise) ? e.promise().done(n.resolve).fail(n.reject).progress(n.notify) : n[o + "With"](this === r ? n.promise() : this, u ? [e] : arguments)
                            })
                        }), e = null
                    }).promise()
                }, promise: function (e) {
                    return null != e ? b.extend(e, r) : r
                }
            }, i = {};
            return r.pipe = r.then, b.each(t, function (e, s) {
                var o = s[2], u = s[3];
                r[s[1]] = o.add, u && o.add(function () {
                    n = u
                }, t[1 ^ e][2].disable, t[2][2].lock), i[s[0]] = function () {
                    return i[s[0] + "With"](this === i ? r : this, arguments), this
                }, i[s[0] + "With"] = o.fireWith
            }), r.promise(i), e && e.call(i, i), i
        }, when: function (e) {
            var t = 0, n = d.call(arguments), r = n.length, i = 1 !== r || e && b.isFunction(e.promise) ? r : 0, s = 1 === i ? e : b.Deferred(), o = function (e, t, n) {
                return function (r) {
                    t[e] = this, n[e] = arguments.length > 1 ? d.call(arguments) : r, n === u ? s.notifyWith(t, n) : --i || s.resolveWith(t, n)
                }
            }, u, a, f;
            if (r > 1)for (u = Array(r), a = Array(r), f = Array(r); r > t; t++)n[t] && b.isFunction(n[t].promise) ? n[t].promise().done(o(t, f, n)).fail(s.reject).progress(o(t, a, u)) : --i;
            return i || s.resolveWith(f, n), s.promise()
        }
    }), b.support = function () {
        var t, n, r, o, u, a, f, l, c, h, p = s.createElement("div");
        if (p.setAttribute("className", "t"), p.innerHTML = "  <link/><table></table><a href='/a'>a</a><input type='checkbox'/>", n = p.getElementsByTagName("*"), r = p.getElementsByTagName("a")[0], !n || !r || !n.length)return {};
        u = s.createElement("select"), f = u.appendChild(s.createElement("option")), o = p.getElementsByTagName("input")[0], r.style.cssText = "top:1px;float:left;opacity:.5", t = {
            getSetAttribute: "t" !== p.className,
            leadingWhitespace: 3 === p.firstChild.nodeType,
            tbody: !p.getElementsByTagName("tbody").length,
            htmlSerialize: !!p.getElementsByTagName("link").length,
            style: /top/.test(r.getAttribute("style")),
            hrefNormalized: "/a" === r.getAttribute("href"),
            opacity: /^0.5/.test(r.style.opacity),
            cssFloat: !!r.style.cssFloat,
            checkOn: !!o.value,
            optSelected: f.selected,
            enctype: !!s.createElement("form").enctype,
            html5Clone: "<:nav></:nav>" !== s.createElement("nav").cloneNode(!0).outerHTML,
            boxModel: "CSS1Compat" === s.compatMode,
            deleteExpando: !0,
            noCloneEvent: !0,
            inlineBlockNeedsLayout: !1,
            shrinkWrapBlocks: !1,
            reliableMarginRight: !0,
            boxSizingReliable: !0,
            pixelPosition: !1
        }, o.checked = !0, t.noCloneChecked = o.cloneNode(!0).checked, u.disabled = !0, t.optDisabled = !f.disabled;
        try {
            delete p.test
        } catch (d) {
            t.deleteExpando = !1
        }
        o = s.createElement("input"), o.setAttribute("value", ""), t.input = "" === o.getAttribute("value"), o.value = "t", o.setAttribute("type", "radio"), t.radioValue = "t" === o.value, o.setAttribute("checked", "t"), o.setAttribute("name", "t"), a = s.createDocumentFragment(), a.appendChild(o), t.appendChecked = o.checked, t.checkClone = a.cloneNode(!0).cloneNode(!0).lastChild.checked, p.attachEvent && (p.attachEvent("onclick", function () {
            t.noCloneEvent = !1
        }), p.cloneNode(!0).click());
        for (h in{
            submit: !0,
            change: !0,
            focusin: !0
        })p.setAttribute(l = "on" + h, "t"), t[h + "Bubbles"] = l in e || p.attributes[l].expando === !1;
        return p.style.backgroundClip = "content-box", p.cloneNode(!0).style.backgroundClip = "", t.clearCloneStyle = "content-box" === p.style.backgroundClip, b(function () {
            var n, r, o, u = "padding:0;margin:0;border:0;display:block;box-sizing:content-box;-moz-box-sizing:content-box;-webkit-box-sizing:content-box;", a = s.getElementsByTagName("body")[0];
            a && (n = s.createElement("div"), n.style.cssText = "border:0;width:0;height:0;position:absolute;top:0;left:-9999px;margin-top:1px", a.appendChild(n).appendChild(p), p.innerHTML = "<table><tr><td></td><td>t</td></tr></table>", o = p.getElementsByTagName("td"), o[0].style.cssText = "padding:0;margin:0;border:0;display:none", c = 0 === o[0].offsetHeight, o[0].style.display = "", o[1].style.display = "none", t.reliableHiddenOffsets = c && 0 === o[0].offsetHeight, p.innerHTML = "", p.style.cssText = "box-sizing:border-box;-moz-box-sizing:border-box;-webkit-box-sizing:border-box;padding:1px;border:1px;display:block;width:4px;margin-top:1%;position:absolute;top:1%;", t.boxSizing = 4 === p.offsetWidth, t.doesNotIncludeMarginInBodyOffset = 1 !== a.offsetTop, e.getComputedStyle && (t.pixelPosition = "1%" !== (e.getComputedStyle(p, null) || {}).top, t.boxSizingReliable = "4px" === (e.getComputedStyle(p, null) || {width: "4px"}).width, r = p.appendChild(s.createElement("div")), r.style.cssText = p.style.cssText = u, r.style.marginRight = r.style.width = "0", p.style.width = "1px", t.reliableMarginRight = !parseFloat((e.getComputedStyle(r, null) || {}).marginRight)), typeof p.style.zoom !== i && (p.innerHTML = "", p.style.cssText = u + "width:1px;padding:1px;display:inline;zoom:1", t.inlineBlockNeedsLayout = 3 === p.offsetWidth, p.style.display = "block", p.innerHTML = "<div></div>", p.firstChild.style.width = "5px", t.shrinkWrapBlocks = 3 !== p.offsetWidth, t.inlineBlockNeedsLayout && (a.style.zoom = 1)), a.removeChild(n), n = p = o = r = null)
        }), n = u = a = f = r = o = null, t
    }();
    var j = /(?:\{[\s\S]*\}|\[[\s\S]*\])$/, F = /([A-Z])/g;
    b.extend({
        cache: {},
        expando: "jQuery" + (c + Math.random()).replace(/\D/g, ""),
        noData: {embed: !0, object: "clsid:D27CDB6E-AE6D-11cf-96B8-444553540000", applet: !0},
        hasData: function (e) {
            return e = e.nodeType ? b.cache[e[b.expando]] : e[b.expando], !!e && !U(e)
        },
        data: function (e, t, n) {
            return I(e, t, n)
        },
        removeData: function (e, t) {
            return q(e, t)
        },
        _data: function (e, t, n) {
            return I(e, t, n, !0)
        },
        _removeData: function (e, t) {
            return q(e, t, !0)
        },
        acceptData: function (e) {
            if (e.nodeType && 1 !== e.nodeType && 9 !== e.nodeType)return !1;
            var t = e.nodeName && b.noData[e.nodeName.toLowerCase()];
            return !t || t !== !0 && e.getAttribute("classid") === t
        }
    }), b.fn.extend({
        data: function (e, n) {
            var r, i, s = this[0], o = 0, u = null;
            if (e === t) {
                if (this.length && (u = b.data(s), 1 === s.nodeType && !b._data(s, "parsedAttrs"))) {
                    for (r = s.attributes; r.length > o; o++)i = r[o].name, i.indexOf("data-") || (i = b.camelCase(i.slice(5)), R(s, i, u[i]));
                    b._data(s, "parsedAttrs", !0)
                }
                return u
            }
            return "object" == typeof e ? this.each(function () {
                b.data(this, e)
            }) : b.access(this, function (n) {
                return n === t ? s ? R(s, e, b.data(s, e)) : null : (this.each(function () {
                    b.data(this, e, n)
                }), t)
            }, null, n, arguments.length > 1, null, !0)
        }, removeData: function (e) {
            return this.each(function () {
                b.removeData(this, e)
            })
        }
    }), b.extend({
        queue: function (e, n, r) {
            var i;
            return e ? (n = (n || "fx") + "queue", i = b._data(e, n), r && (!i || b.isArray(r) ? i = b._data(e, n, b.makeArray(r)) : i.push(r)), i || []) : t
        }, dequeue: function (e, t) {
            t = t || "fx";
            var n = b.queue(e, t), r = n.length, i = n.shift(), s = b._queueHooks(e, t), o = function () {
                b.dequeue(e, t)
            };
            "inprogress" === i && (i = n.shift(), r--), s.cur = i, i && ("fx" === t && n.unshift("inprogress"), delete s.stop, i.call(e, o, s)), !r && s && s.empty.fire()
        }, _queueHooks: function (e, t) {
            var n = t + "queueHooks";
            return b._data(e, n) || b._data(e, n, {
                    empty: b.Callbacks("once memory").add(function () {
                        b._removeData(e, t + "queue"), b._removeData(e, n)
                    })
                })
        }
    }), b.fn.extend({
        queue: function (e, n) {
            var r = 2;
            return "string" != typeof e && (n = e, e = "fx", r--), r > arguments.length ? b.queue(this[0], e) : n === t ? this : this.each(function () {
                var t = b.queue(this, e, n);
                b._queueHooks(this, e), "fx" === e && "inprogress" !== t[0] && b.dequeue(this, e)
            })
        }, dequeue: function (e) {
            return this.each(function () {
                b.dequeue(this, e)
            })
        }, delay: function (e, t) {
            return e = b.fx ? b.fx.speeds[e] || e : e, t = t || "fx", this.queue(t, function (t, n) {
                var r = setTimeout(t, e);
                n.stop = function () {
                    clearTimeout(r)
                }
            })
        }, clearQueue: function (e) {
            return this.queue(e || "fx", [])
        }, promise: function (e, n) {
            var r, i = 1, s = b.Deferred(), o = this, u = this.length, a = function () {
                --i || s.resolveWith(o, [o])
            };
            "string" != typeof e && (n = e, e = t), e = e || "fx";
            while (u--)r = b._data(o[u], e + "queueHooks"), r && r.empty && (i++, r.empty.add(a));
            return a(), s.promise(n)
        }
    });
    var z, W, X = /[\t\r\n]/g, V = /\r/g, $ = /^(?:input|select|textarea|button|object)$/i, J = /^(?:a|area)$/i, K = /^(?:checked|selected|autofocus|autoplay|async|controls|defer|disabled|hidden|loop|multiple|open|readonly|required|scoped)$/i, Q = /^(?:checked|selected)$/i, G = b.support.getSetAttribute, Y = b.support.input;
    b.fn.extend({
        attr: function (e, t) {
            return b.access(this, b.attr, e, t, arguments.length > 1)
        }, removeAttr: function (e) {
            return this.each(function () {
                b.removeAttr(this, e)
            })
        }, prop: function (e, t) {
            return b.access(this, b.prop, e, t, arguments.length > 1)
        }, removeProp: function (e) {
            return e = b.propFix[e] || e, this.each(function () {
                try {
                    this[e] = t, delete this[e]
                } catch (n) {
                }
            })
        }, addClass: function (e) {
            var t, n, r, i, s, o = 0, u = this.length, a = "string" == typeof e && e;
            if (b.isFunction(e))return this.each(function (t) {
                b(this).addClass(e.call(this, t, this.className))
            });
            if (a)for (t = (e || "").match(E) || []; u > o; o++)if (n = this[o], r = 1 === n.nodeType && (n.className ? (" " + n.className + " ").replace(X, " ") : " ")) {
                s = 0;
                while (i = t[s++])0 > r.indexOf(" " + i + " ") && (r += i + " ");
                n.className = b.trim(r)
            }
            return this
        }, removeClass: function (e) {
            var t, n, r, i, s, o = 0, u = this.length, a = 0 === arguments.length || "string" == typeof e && e;
            if (b.isFunction(e))return this.each(function (t) {
                b(this).removeClass(e.call(this, t, this.className))
            });
            if (a)for (t = (e || "").match(E) || []; u > o; o++)if (n = this[o], r = 1 === n.nodeType && (n.className ? (" " + n.className + " ").replace(X, " ") : "")) {
                s = 0;
                while (i = t[s++])while (r.indexOf(" " + i + " ") >= 0)r = r.replace(" " + i + " ", " ");
                n.className = e ? b.trim(r) : ""
            }
            return this
        }, toggleClass: function (e, t) {
            var n = typeof e, r = "boolean" == typeof t;
            return b.isFunction(e) ? this.each(function (n) {
                b(this).toggleClass(e.call(this, n, this.className, t), t)
            }) : this.each(function () {
                if ("string" === n) {
                    var s, o = 0, u = b(this), a = t, f = e.match(E) || [];
                    while (s = f[o++])a = r ? a : !u.hasClass(s), u[a ? "addClass" : "removeClass"](s)
                } else(n === i || "boolean" === n) && (this.className && b._data(this, "__className__", this.className), this.className = this.className || e === !1 ? "" : b._data(this, "__className__") || "")
            })
        }, hasClass: function (e) {
            var t = " " + e + " ", n = 0, r = this.length;
            for (; r > n; n++)if (1 === this[n].nodeType && (" " + this[n].className + " ").replace(X, " ").indexOf(t) >= 0)return !0;
            return !1
        }, val: function (e) {
            var n, r, i, s = this[0];
            if (arguments.length)return i = b.isFunction(e), this.each(function (n) {
                var s, o = b(this);
                1 === this.nodeType && (s = i ? e.call(this, n, o.val()) : e, null == s ? s = "" : "number" == typeof s ? s += "" : b.isArray(s) && (s = b.map(s, function (e) {
                    return null == e ? "" : e + ""
                })), r = b.valHooks[this.type] || b.valHooks[this.nodeName.toLowerCase()], r && "set"in r && r.set(this, s, "value") !== t || (this.value = s))
            });
            if (s)return r = b.valHooks[s.type] || b.valHooks[s.nodeName.toLowerCase()], r && "get"in r && (n = r.get(s, "value")) !== t ? n : (n = s.value, "string" == typeof n ? n.replace(V, "") : null == n ? "" : n)
        }
    }), b.extend({
        valHooks: {
            option: {
                get: function (e) {
                    var t = e.attributes.value;
                    return !t || t.specified ? e.value : e.text
                }
            }, select: {
                get: function (e) {
                    var t, n, r = e.options, i = e.selectedIndex, s = "select-one" === e.type || 0 > i, o = s ? null : [], u = s ? i + 1 : r.length, a = 0 > i ? u : s ? i : 0;
                    for (; u > a; a++)if (n = r[a], !(!n.selected && a !== i || (b.support.optDisabled ? n.disabled : null !== n.getAttribute("disabled")) || n.parentNode.disabled && b.nodeName(n.parentNode, "optgroup"))) {
                        if (t = b(n).val(), s)return t;
                        o.push(t)
                    }
                    return o
                }, set: function (e, t) {
                    var n = b.makeArray(t);
                    return b(e).find("option").each(function () {
                        this.selected = b.inArray(b(this).val(), n) >= 0
                    }), n.length || (e.selectedIndex = -1), n
                }
            }
        },
        attr: function (e, n, r) {
            var s, o, u, a = e.nodeType;
            if (e && 3 !== a && 8 !== a && 2 !== a)return typeof e.getAttribute === i ? b.prop(e, n, r) : (o = 1 !== a || !b.isXMLDoc(e), o && (n = n.toLowerCase(), s = b.attrHooks[n] || (K.test(n) ? W : z)), r === t ? s && o && "get"in s && null !== (u = s.get(e, n)) ? u : (typeof e.getAttribute !== i && (u = e.getAttribute(n)), null == u ? t : u) : null !== r ? s && o && "set"in s && (u = s.set(e, r, n)) !== t ? u : (e.setAttribute(n, r + ""), r) : (b.removeAttr(e, n), t))
        },
        removeAttr: function (e, t) {
            var n, r, i = 0, s = t && t.match(E);
            if (s && 1 === e.nodeType)while (n = s[i++])r = b.propFix[n] || n, K.test(n) ? !G && Q.test(n) ? e[b.camelCase("default-" + n)] = e[r] = !1 : e[r] = !1 : b.attr(e, n, ""), e.removeAttribute(G ? n : r)
        },
        attrHooks: {
            type: {
                set: function (e, t) {
                    if (!b.support.radioValue && "radio" === t && b.nodeName(e, "input")) {
                        var n = e.value;
                        return e.setAttribute("type", t), n && (e.value = n), t
                    }
                }
            }
        },
        propFix: {
            tabindex: "tabIndex",
            readonly: "readOnly",
            "for": "htmlFor",
            "class": "className",
            maxlength: "maxLength",
            cellspacing: "cellSpacing",
            cellpadding: "cellPadding",
            rowspan: "rowSpan",
            colspan: "colSpan",
            usemap: "useMap",
            frameborder: "frameBorder",
            contenteditable: "contentEditable"
        },
        prop: function (e, n, r) {
            var i, s, o, u = e.nodeType;
            if (e && 3 !== u && 8 !== u && 2 !== u)return o = 1 !== u || !b.isXMLDoc(e), o && (n = b.propFix[n] || n, s = b.propHooks[n]), r !== t ? s && "set"in s && (i = s.set(e, r, n)) !== t ? i : e[n] = r : s && "get"in s && null !== (i = s.get(e, n)) ? i : e[n]
        },
        propHooks: {
            tabIndex: {
                get: function (e) {
                    var n = e.getAttributeNode("tabindex");
                    return n && n.specified ? parseInt(n.value, 10) : $.test(e.nodeName) || J.test(e.nodeName) && e.href ? 0 : t
                }
            }
        }
    }), W = {
        get: function (e, n) {
            var r = b.prop(e, n), i = "boolean" == typeof r && e.getAttribute(n), s = "boolean" == typeof r ? Y && G ? null != i : Q.test(n) ? e[b.camelCase("default-" + n)] : !!i : e.getAttributeNode(n);
            return s && s.value !== !1 ? n.toLowerCase() : t
        }, set: function (e, t, n) {
            return t === !1 ? b.removeAttr(e, n) : Y && G || !Q.test(n) ? e.setAttribute(!G && b.propFix[n] || n, n) : e[b.camelCase("default-" + n)] = e[n] = !0, n
        }
    }, Y && G || (b.attrHooks.value = {
        get: function (e, n) {
            var r = e.getAttributeNode(n);
            return b.nodeName(e, "input") ? e.defaultValue : r && r.specified ? r.value : t
        }, set: function (e, n, r) {
            return b.nodeName(e, "input") ? (e.defaultValue = n, t) : z && z.set(e, n, r)
        }
    }), G || (z = b.valHooks.button = {
        get: function (e, n) {
            var r = e.getAttributeNode(n);
            return r && ("id" === n || "name" === n || "coords" === n ? "" !== r.value : r.specified) ? r.value : t
        }, set: function (e, n, r) {
            var i = e.getAttributeNode(r);
            return i || e.setAttributeNode(i = e.ownerDocument.createAttribute(r)), i.value = n += "", "value" === r || n === e.getAttribute(r) ? n : t
        }
    }, b.attrHooks.contenteditable = {
        get: z.get, set: function (e, t, n) {
            z.set(e, "" === t ? !1 : t, n)
        }
    }, b.each(["width", "height"], function (e, n) {
        b.attrHooks[n] = b.extend(b.attrHooks[n], {
            set: function (e, r) {
                return "" === r ? (e.setAttribute(n, "auto"), r) : t
            }
        })
    })), b.support.hrefNormalized || (b.each(["href", "src", "width", "height"], function (e, n) {
        b.attrHooks[n] = b.extend(b.attrHooks[n], {
            get: function (e) {
                var r = e.getAttribute(n, 2);
                return null == r ? t : r
            }
        })
    }), b.each(["href", "src"], function (e, t) {
        b.propHooks[t] = {
            get: function (e) {
                return e.getAttribute(t, 4)
            }
        }
    })), b.support.style || (b.attrHooks.style = {
        get: function (e) {
            return e.style.cssText || t
        }, set: function (e, t) {
            return e.style.cssText = t + ""
        }
    }), b.support.optSelected || (b.propHooks.selected = b.extend(b.propHooks.selected, {
        get: function (e) {
            var t = e.parentNode;
            return t && (t.selectedIndex, t.parentNode && t.parentNode.selectedIndex), null
        }
    })), b.support.enctype || (b.propFix.enctype = "encoding"), b.support.checkOn || b.each(["radio", "checkbox"], function () {
        b.valHooks[this] = {
            get: function (e) {
                return null === e.getAttribute("value") ? "on" : e.value
            }
        }
    }), b.each(["radio", "checkbox"], function () {
        b.valHooks[this] = b.extend(b.valHooks[this], {
            set: function (e, n) {
                return b.isArray(n) ? e.checked = b.inArray(b(e).val(), n) >= 0 : t
            }
        })
    });
    var Z = /^(?:input|select|textarea)$/i, et = /^key/, tt = /^(?:mouse|contextmenu)|click/, nt = /^(?:focusinfocus|focusoutblur)$/, rt = /^([^.]*)(?:\.(.+)|)$/;
    b.event = {
        global: {},
        add: function (e, n, r, s, o) {
            var u, a, f, l, c, h, p, d, v, m, g, y = b._data(e);
            if (y) {
                r.handler && (l = r, r = l.handler, o = l.selector), r.guid || (r.guid = b.guid++), (a = y.events) || (a = y.events = {}), (h = y.handle) || (h = y.handle = function (e) {
                    return typeof b === i || e && b.event.triggered === e.type ? t : b.event.dispatch.apply(h.elem, arguments)
                }, h.elem = e), n = (n || "").match(E) || [""], f = n.length;
                while (f--)u = rt.exec(n[f]) || [], v = g = u[1], m = (u[2] || "").split(".").sort(), c = b.event.special[v] || {}, v = (o ? c.delegateType : c.bindType) || v, c = b.event.special[v] || {}, p = b.extend({
                    type: v,
                    origType: g,
                    data: s,
                    handler: r,
                    guid: r.guid,
                    selector: o,
                    needsContext: o && b.expr.match.needsContext.test(o),
                    namespace: m.join(".")
                }, l), (d = a[v]) || (d = a[v] = [], d.delegateCount = 0, c.setup && c.setup.call(e, s, m, h) !== !1 || (e.addEventListener ? e.addEventListener(v, h, !1) : e.attachEvent && e.attachEvent("on" + v, h))), c.add && (c.add.call(e, p), p.handler.guid || (p.handler.guid = r.guid)), o ? d.splice(d.delegateCount++, 0, p) : d.push(p), b.event.global[v] = !0;
                e = null
            }
        },
        remove: function (e, t, n, r, i) {
            var s, o, u, a, f, l, c, h, p, d, v, m = b.hasData(e) && b._data(e);
            if (m && (l = m.events)) {
                t = (t || "").match(E) || [""], f = t.length;
                while (f--)if (u = rt.exec(t[f]) || [], p = v = u[1], d = (u[2] || "").split(".").sort(), p) {
                    c = b.event.special[p] || {}, p = (r ? c.delegateType : c.bindType) || p, h = l[p] || [], u = u[2] && RegExp("(^|\\.)" + d.join("\\.(?:.*\\.|)") + "(\\.|$)"), a = s = h.length;
                    while (s--)o = h[s], !i && v !== o.origType || n && n.guid !== o.guid || u && !u.test(o.namespace) || r && r !== o.selector && ("**" !== r || !o.selector) || (h.splice(s, 1), o.selector && h.delegateCount--, c.remove && c.remove.call(e, o));
                    a && !h.length && (c.teardown && c.teardown.call(e, d, m.handle) !== !1 || b.removeEvent(e, p, m.handle), delete l[p])
                } else for (p in l)b.event.remove(e, p + t[f], n, r, !0);
                b.isEmptyObject(l) && (delete m.handle, b._removeData(e, "events"))
            }
        },
        trigger: function (n, r, i, o) {
            var u, a, f, l, c, h, p, d = [i || s], v = g.call(n, "type") ? n.type : n, m = g.call(n, "namespace") ? n.namespace.split(".") : [];
            if (f = h = i = i || s, 3 !== i.nodeType && 8 !== i.nodeType && !nt.test(v + b.event.triggered) && (v.indexOf(".") >= 0 && (m = v.split("."), v = m.shift(), m.sort()), a = 0 > v.indexOf(":") && "on" + v, n = n[b.expando] ? n : new b.Event(v, "object" == typeof n && n), n.isTrigger = !0, n.namespace = m.join("."), n.namespace_re = n.namespace ? RegExp("(^|\\.)" + m.join("\\.(?:.*\\.|)") + "(\\.|$)") : null, n.result = t, n.target || (n.target = i), r = null == r ? [n] : b.makeArray(r, [n]), c = b.event.special[v] || {}, o || !c.trigger || c.trigger.apply(i, r) !== !1)) {
                if (!o && !c.noBubble && !b.isWindow(i)) {
                    for (l = c.delegateType || v, nt.test(l + v) || (f = f.parentNode); f; f = f.parentNode)d.push(f), h = f;
                    h === (i.ownerDocument || s) && d.push(h.defaultView || h.parentWindow || e)
                }
                p = 0;
                while ((f = d[p++]) && !n.isPropagationStopped())n.type = p > 1 ? l : c.bindType || v, u = (b._data(f, "events") || {})[n.type] && b._data(f, "handle"), u && u.apply(f, r), u = a && f[a], u && b.acceptData(f) && u.apply && u.apply(f, r) === !1 && n.preventDefault();
                if (n.type = v, !(o || n.isDefaultPrevented() || c._default && c._default.apply(i.ownerDocument, r) !== !1 || "click" === v && b.nodeName(i, "a") || !b.acceptData(i) || !a || !i[v] || b.isWindow(i))) {
                    h = i[a], h && (i[a] = null), b.event.triggered = v;
                    try {
                        i[v]()
                    } catch (y) {
                    }
                    b.event.triggered = t, h && (i[a] = h)
                }
                return n.result
            }
        },
        dispatch: function (e) {
            e = b.event.fix(e);
            var n, r, i, s, o, u = [], a = d.call(arguments), f = (b._data(this, "events") || {})[e.type] || [], l = b.event.special[e.type] || {};
            if (a[0] = e, e.delegateTarget = this, !l.preDispatch || l.preDispatch.call(this, e) !== !1) {
                u = b.event.handlers.call(this, e, f), n = 0;
                while ((s = u[n++]) && !e.isPropagationStopped()) {
                    e.currentTarget = s.elem, o = 0;
                    while ((i = s.handlers[o++]) && !e.isImmediatePropagationStopped())(!e.namespace_re || e.namespace_re.test(i.namespace)) && (e.handleObj = i, e.data = i.data, r = ((b.event.special[i.origType] || {}).handle || i.handler).apply(s.elem, a), r !== t && (e.result = r) === !1 && (e.preventDefault(), e.stopPropagation()))
                }
                return l.postDispatch && l.postDispatch.call(this, e), e.result
            }
        },
        handlers: function (e, n) {
            var r, i, s, o, u = [], a = n.delegateCount, f = e.target;
            if (a && f.nodeType && (!e.button || "click" !== e.type))for (; f != this; f = f.parentNode || this)if (1 === f.nodeType && (f.disabled !== !0 || "click" !== e.type)) {
                for (s = [], o = 0; a > o; o++)i = n[o], r = i.selector + " ", s[r] === t && (s[r] = i.needsContext ? b(r, this).index(f) >= 0 : b.find(r, this, null, [f]).length), s[r] && s.push(i);
                s.length && u.push({elem: f, handlers: s})
            }
            return n.length > a && u.push({elem: this, handlers: n.slice(a)}), u
        },
        fix: function (e) {
            if (e[b.expando])return e;
            var t, n, r, i = e.type, o = e, u = this.fixHooks[i];
            u || (this.fixHooks[i] = u = tt.test(i) ? this.mouseHooks : et.test(i) ? this.keyHooks : {}), r = u.props ? this.props.concat(u.props) : this.props, e = new b.Event(o), t = r.length;
            while (t--)n = r[t], e[n] = o[n];
            return e.target || (e.target = o.srcElement || s), 3 === e.target.nodeType && (e.target = e.target.parentNode), e.metaKey = !!e.metaKey, u.filter ? u.filter(e, o) : e
        },
        props: "altKey bubbles cancelable ctrlKey currentTarget eventPhase metaKey relatedTarget shiftKey target timeStamp view which".split(" "),
        fixHooks: {},
        keyHooks: {
            props: "char charCode key keyCode".split(" "), filter: function (e, t) {
                return null == e.which && (e.which = null != t.charCode ? t.charCode : t.keyCode), e
            }
        },
        mouseHooks: {
            props: "button buttons clientX clientY fromElement offsetX offsetY pageX pageY screenX screenY toElement".split(" "),
            filter: function (e, n) {
                var r, i, o, u = n.button, a = n.fromElement;
                return null == e.pageX && null != n.clientX && (i = e.target.ownerDocument || s, o = i.documentElement, r = i.body, e.pageX = n.clientX + (o && o.scrollLeft || r && r.scrollLeft || 0) - (o && o.clientLeft || r && r.clientLeft || 0), e.pageY = n.clientY + (o && o.scrollTop || r && r.scrollTop || 0) - (o && o.clientTop || r && r.clientTop || 0)), !e.relatedTarget && a && (e.relatedTarget = a === e.target ? n.toElement : a), e.which || u === t || (e.which = 1 & u ? 1 : 2 & u ? 3 : 4 & u ? 2 : 0), e
            }
        },
        special: {
            load: {noBubble: !0}, click: {
                trigger: function () {
                    return b.nodeName(this, "input") && "checkbox" === this.type && this.click ? (this.click(), !1) : t
                }
            }, focus: {
                trigger: function () {
                    if (this !== s.activeElement && this.focus)try {
                        return this.focus(), !1
                    } catch (e) {
                    }
                }, delegateType: "focusin"
            }, blur: {
                trigger: function () {
                    return this === s.activeElement && this.blur ? (this.blur(), !1) : t
                }, delegateType: "focusout"
            }, beforeunload: {
                postDispatch: function (e) {
                    e.result !== t && (e.originalEvent.returnValue = e.result)
                }
            }
        },
        simulate: function (e, t, n, r) {
            var i = b.extend(new b.Event, n, {type: e, isSimulated: !0, originalEvent: {}});
            r ? b.event.trigger(i, null, t) : b.event.dispatch.call(t, i), i.isDefaultPrevented() && n.preventDefault()
        }
    }, b.removeEvent = s.removeEventListener ? function (e, t, n) {
        e.removeEventListener && e.removeEventListener(t, n, !1)
    } : function (e, t, n) {
        var r = "on" + t;
        e.detachEvent && (typeof e[r] === i && (e[r] = null), e.detachEvent(r, n))
    }, b.Event = function (e, n) {
        return this instanceof b.Event ? (e && e.type ? (this.originalEvent = e, this.type = e.type, this.isDefaultPrevented = e.defaultPrevented || e.returnValue === !1 || e.getPreventDefault && e.getPreventDefault() ? it : st) : this.type = e, n && b.extend(this, n), this.timeStamp = e && e.timeStamp || b.now(), this[b.expando] = !0, t) : new b.Event(e, n)
    }, b.Event.prototype = {
        isDefaultPrevented: st,
        isPropagationStopped: st,
        isImmediatePropagationStopped: st,
        preventDefault: function () {
            var e = this.originalEvent;
            this.isDefaultPrevented = it, e && (e.preventDefault ? e.preventDefault() : e.returnValue = !1)
        },
        stopPropagation: function () {
            var e = this.originalEvent;
            this.isPropagationStopped = it, e && (e.stopPropagation && e.stopPropagation(), e.cancelBubble = !0)
        },
        stopImmediatePropagation: function () {
            this.isImmediatePropagationStopped = it, this.stopPropagation()
        }
    }, b.each({mouseenter: "mouseover", mouseleave: "mouseout"}, function (e, t) {
        b.event.special[e] = {
            delegateType: t, bindType: t, handle: function (e) {
                var n, r = this, i = e.relatedTarget, s = e.handleObj;
                return (!i || i !== r && !b.contains(r, i)) && (e.type = s.origType, n = s.handler.apply(this, arguments), e.type = t), n
            }
        }
    }), b.support.submitBubbles || (b.event.special.submit = {
        setup: function () {
            return b.nodeName(this, "form") ? !1 : (b.event.add(this, "click._submit keypress._submit", function (e) {
                var n = e.target, r = b.nodeName(n, "input") || b.nodeName(n, "button") ? n.form : t;
                r && !b._data(r, "submitBubbles") && (b.event.add(r, "submit._submit", function (e) {
                    e._submit_bubble = !0
                }), b._data(r, "submitBubbles", !0))
            }), t)
        }, postDispatch: function (e) {
            e._submit_bubble && (delete e._submit_bubble, this.parentNode && !e.isTrigger && b.event.simulate("submit", this.parentNode, e, !0))
        }, teardown: function () {
            return b.nodeName(this, "form") ? !1 : (b.event.remove(this, "._submit"), t)
        }
    }), b.support.changeBubbles || (b.event.special.change = {
        setup: function () {
            return Z.test(this.nodeName) ? (("checkbox" === this.type || "radio" === this.type) && (b.event.add(this, "propertychange._change", function (e) {
                "checked" === e.originalEvent.propertyName && (this._just_changed = !0)
            }), b.event.add(this, "click._change", function (e) {
                this._just_changed && !e.isTrigger && (this._just_changed = !1), b.event.simulate("change", this, e, !0)
            })), !1) : (b.event.add(this, "beforeactivate._change", function (e) {
                var t = e.target;
                Z.test(t.nodeName) && !b._data(t, "changeBubbles") && (b.event.add(t, "change._change", function (e) {
                    !this.parentNode || e.isSimulated || e.isTrigger || b.event.simulate("change", this.parentNode, e, !0)
                }), b._data(t, "changeBubbles", !0))
            }), t)
        }, handle: function (e) {
            var n = e.target;
            return this !== n || e.isSimulated || e.isTrigger || "radio" !== n.type && "checkbox" !== n.type ? e.handleObj.handler.apply(this, arguments) : t
        }, teardown: function () {
            return b.event.remove(this, "._change"), !Z.test(this.nodeName)
        }
    }), b.support.focusinBubbles || b.each({focus: "focusin", blur: "focusout"}, function (e, t) {
        var n = 0, r = function (e) {
            b.event.simulate(t, e.target, b.event.fix(e), !0)
        };
        b.event.special[t] = {
            setup: function () {
                0 === n++ && s.addEventListener(e, r, !0)
            }, teardown: function () {
                0 === --n && s.removeEventListener(e, r, !0)
            }
        }
    }), b.fn.extend({
        on: function (e, n, r, i, s) {
            var o, u;
            if ("object" == typeof e) {
                "string" != typeof n && (r = r || n, n = t);
                for (o in e)this.on(o, n, r, e[o], s);
                return this
            }
            if (null == r && null == i ? (i = n, r = n = t) : null == i && ("string" == typeof n ? (i = r, r = t) : (i = r, r = n, n = t)), i === !1)i = st; else if (!i)return this;
            return 1 === s && (u = i, i = function (e) {
                return b().off(e), u.apply(this, arguments)
            }, i.guid = u.guid || (u.guid = b.guid++)), this.each(function () {
                b.event.add(this, e, i, r, n)
            })
        }, one: function (e, t, n, r) {
            return this.on(e, t, n, r, 1)
        }, off: function (e, n, r) {
            var i, s;
            if (e && e.preventDefault && e.handleObj)return i = e.handleObj, b(e.delegateTarget).off(i.namespace ? i.origType + "." + i.namespace : i.origType, i.selector, i.handler), this;
            if ("object" == typeof e) {
                for (s in e)this.off(s, n, e[s]);
                return this
            }
            return (n === !1 || "function" == typeof n) && (r = n, n = t), r === !1 && (r = st), this.each(function () {
                b.event.remove(this, e, r, n)
            })
        }, bind: function (e, t, n) {
            return this.on(e, null, t, n)
        }, unbind: function (e, t) {
            return this.off(e, null, t)
        }, delegate: function (e, t, n, r) {
            return this.on(t, e, n, r)
        }, undelegate: function (e, t, n) {
            return 1 === arguments.length ? this.off(e, "**") : this.off(t, e || "**", n)
        }, trigger: function (e, t) {
            return this.each(function () {
                b.event.trigger(e, t, this)
            })
        }, triggerHandler: function (e, n) {
            var r = this[0];
            return r ? b.event.trigger(e, n, r, !0) : t
        }
    }), function (e, t) {
        function rt(e) {
            return J.test(e + "")
        }

        function it() {
            var e, t = [];
            return e = function (n, r) {
                return t.push(n += " ") > i.cacheLength && delete e[t.shift()], e[n] = r
            }
        }

        function st(e) {
            return e[w] = !0, e
        }

        function ot(e) {
            var t = c.createElement("div");
            try {
                return e(t)
            } catch (n) {
                return !1
            } finally {
                t = null
            }
        }

        function ut(e, t, n, r) {
            var i, s, o, u, a, f, h, v, m, y;
            if ((t ? t.ownerDocument || t : E) !== c && l(t), t = t || c, n = n || [], !e || "string" != typeof e)return n;
            if (1 !== (u = t.nodeType) && 9 !== u)return [];
            if (!p && !r) {
                if (i = K.exec(e))if (o = i[1]) {
                    if (9 === u) {
                        if (s = t.getElementById(o), !s || !s.parentNode)return n;
                        if (s.id === o)return n.push(s), n
                    } else if (t.ownerDocument && (s = t.ownerDocument.getElementById(o)) && g(t, s) && s.id === o)return n.push(s), n
                } else {
                    if (i[2])return _.apply(n, D.call(t.getElementsByTagName(e), 0)), n;
                    if ((o = i[3]) && S.getByClassName && t.getElementsByClassName)return _.apply(n, D.call(t.getElementsByClassName(o), 0)), n
                }
                if (S.qsa && !d.test(e)) {
                    if (h = !0, v = w, m = t, y = 9 === u && e, 1 === u && "object" !== t.nodeName.toLowerCase()) {
                        f = ht(e), (h = t.getAttribute("id")) ? v = h.replace(Y, "\\$&") : t.setAttribute("id", v), v = "[id='" + v + "'] ", a = f.length;
                        while (a--)f[a] = v + pt(f[a]);
                        m = $.test(e) && t.parentNode || t, y = f.join(",")
                    }
                    if (y)try {
                        return _.apply(n, D.call(m.querySelectorAll(y), 0)), n
                    } catch (b) {
                    } finally {
                        h || t.removeAttribute("id")
                    }
                }
            }
            return Et(e.replace(R, "$1"), t, n, r)
        }

        function at(e, t) {
            var n = t && e, r = n && (~t.sourceIndex || A) - (~e.sourceIndex || A);
            if (r)return r;
            if (n)while (n = n.nextSibling)if (n === t)return -1;
            return e ? 1 : -1
        }

        function ft(e) {
            return function (t) {
                var n = t.nodeName.toLowerCase();
                return "input" === n && t.type === e
            }
        }

        function lt(e) {
            return function (t) {
                var n = t.nodeName.toLowerCase();
                return ("input" === n || "button" === n) && t.type === e
            }
        }

        function ct(e) {
            return st(function (t) {
                return t = +t, st(function (n, r) {
                    var i, s = e([], n.length, t), o = s.length;
                    while (o--)n[i = s[o]] && (n[i] = !(r[i] = n[i]))
                })
            })
        }

        function ht(e, t) {
            var n, r, s, o, u, a, f, l = C[e + " "];
            if (l)return t ? 0 : l.slice(0);
            u = e, a = [], f = i.preFilter;
            while (u) {
                (!n || (r = U.exec(u))) && (r && (u = u.slice(r[0].length) || u), a.push(s = [])), n = !1, (r = z.exec(u)) && (n = r.shift(), s.push({
                    value: n,
                    type: r[0].replace(R, " ")
                }), u = u.slice(n.length));
                for (o in i.filter)!(r = V[o].exec(u)) || f[o] && !(r = f[o](r)) || (n = r.shift(), s.push({
                    value: n,
                    type: o,
                    matches: r
                }), u = u.slice(n.length));
                if (!n)break
            }
            return t ? u.length : u ? ut.error(e) : C(e, a).slice(0)
        }

        function pt(e) {
            var t = 0, n = e.length, r = "";
            for (; n > t; t++)r += e[t].value;
            return r
        }

        function dt(e, t, n) {
            var i = t.dir, s = n && "parentNode" === i, o = T++;
            return t.first ? function (t, n, r) {
                while (t = t[i])if (1 === t.nodeType || s)return e(t, n, r)
            } : function (t, n, u) {
                var a, f, l, c = x + " " + o;
                if (u) {
                    while (t = t[i])if ((1 === t.nodeType || s) && e(t, n, u))return !0
                } else while (t = t[i])if (1 === t.nodeType || s)if (l = t[w] || (t[w] = {}), (f = l[i]) && f[0] === c) {
                    if ((a = f[1]) === !0 || a === r)return a === !0
                } else if (f = l[i] = [c], f[1] = e(t, n, u) || r, f[1] === !0)return !0
            }
        }

        function vt(e) {
            return e.length > 1 ? function (t, n, r) {
                var i = e.length;
                while (i--)if (!e[i](t, n, r))return !1;
                return !0
            } : e[0]
        }

        function mt(e, t, n, r, i) {
            var s, o = [], u = 0, a = e.length, f = null != t;
            for (; a > u; u++)(s = e[u]) && (!n || n(s, r, i)) && (o.push(s), f && t.push(u));
            return o
        }

        function gt(e, t, n, r, i, s) {
            return r && !r[w] && (r = gt(r)), i && !i[w] && (i = gt(i, s)), st(function (s, o, u, a) {
                var f, l, c, h = [], p = [], d = o.length, v = s || wt(t || "*", u.nodeType ? [u] : u, []), m = !e || !s && t ? v : mt(v, h, e, u, a), g = n ? i || (s ? e : d || r) ? [] : o : m;
                if (n && n(m, g, u, a), r) {
                    f = mt(g, p), r(f, [], u, a), l = f.length;
                    while (l--)(c = f[l]) && (g[p[l]] = !(m[p[l]] = c))
                }
                if (s) {
                    if (i || e) {
                        if (i) {
                            f = [], l = g.length;
                            while (l--)(c = g[l]) && f.push(m[l] = c);
                            i(null, g = [], f, a)
                        }
                        l = g.length;
                        while (l--)(c = g[l]) && (f = i ? P.call(s, c) : h[l]) > -1 && (s[f] = !(o[f] = c))
                    }
                } else g = mt(g === o ? g.splice(d, g.length) : g), i ? i(null, o, g, a) : _.apply(o, g)
            })
        }

        function yt(e) {
            var t, n, r, s = e.length, o = i.relative[e[0].type], u = o || i.relative[" "], a = o ? 1 : 0, l = dt(function (e) {
                return e === t
            }, u, !0), c = dt(function (e) {
                return P.call(t, e) > -1
            }, u, !0), h = [function (e, n, r) {
                return !o && (r || n !== f) || ((t = n).nodeType ? l(e, n, r) : c(e, n, r))
            }];
            for (; s > a; a++)if (n = i.relative[e[a].type])h = [dt(vt(h), n)]; else {
                if (n = i.filter[e[a].type].apply(null, e[a].matches), n[w]) {
                    for (r = ++a; s > r; r++)if (i.relative[e[r].type])break;
                    return gt(a > 1 && vt(h), a > 1 && pt(e.slice(0, a - 1)).replace(R, "$1"), n, r > a && yt(e.slice(a, r)), s > r && yt(e = e.slice(r)), s > r && pt(e))
                }
                h.push(n)
            }
            return vt(h)
        }

        function bt(e, t) {
            var n = 0, s = t.length > 0, o = e.length > 0, u = function (u, a, l, h, p) {
                var d, v, m, g = [], y = 0, b = "0", w = u && [], E = null != p, S = f, T = u || o && i.find.TAG("*", p && a.parentNode || a), N = x += null == S ? 1 : Math.random() || .1;
                for (E && (f = a !== c && a, r = n); null != (d = T[b]); b++) {
                    if (o && d) {
                        v = 0;
                        while (m = e[v++])if (m(d, a, l)) {
                            h.push(d);
                            break
                        }
                        E && (x = N, r = ++n)
                    }
                    s && ((d = !m && d) && y--, u && w.push(d))
                }
                if (y += b, s && b !== y) {
                    v = 0;
                    while (m = t[v++])m(w, g, a, l);
                    if (u) {
                        if (y > 0)while (b--)w[b] || g[b] || (g[b] = M.call(h));
                        g = mt(g)
                    }
                    _.apply(h, g), E && !u && g.length > 0 && y + t.length > 1 && ut.uniqueSort(h)
                }
                return E && (x = N, f = S), w
            };
            return s ? st(u) : u
        }

        function wt(e, t, n) {
            var r = 0, i = t.length;
            for (; i > r; r++)ut(e, t[r], n);
            return n
        }

        function Et(e, t, n, r) {
            var s, o, a, f, l, c = ht(e);
            if (!r && 1 === c.length) {
                if (o = c[0] = c[0].slice(0), o.length > 2 && "ID" === (a = o[0]).type && 9 === t.nodeType && !p && i.relative[o[1].type]) {
                    if (t = i.find.ID(a.matches[0].replace(et, tt), t)[0], !t)return n;
                    e = e.slice(o.shift().value.length)
                }
                s = V.needsContext.test(e) ? 0 : o.length;
                while (s--) {
                    if (a = o[s], i.relative[f = a.type])break;
                    if ((l = i.find[f]) && (r = l(a.matches[0].replace(et, tt), $.test(o[0].type) && t.parentNode || t))) {
                        if (o.splice(s, 1), e = r.length && pt(o), !e)return _.apply(n, D.call(r, 0)), n;
                        break
                    }
                }
            }
            return u(e, c)(r, t, p, n, $.test(e)), n
        }

        function St() {
        }

        var n, r, i, s, o, u, a, f, l, c, h, p, d, v, m, g, y, w = "sizzle" + -(new Date), E = e.document, S = {}, x = 0, T = 0, N = it(), C = it(), k = it(), L = typeof t, A = 1 << 31, O = [], M = O.pop, _ = O.push, D = O.slice, P = O.indexOf || function (e) {
                var t = 0, n = this.length;
                for (; n > t; t++)if (this[t] === e)return t;
                return -1
            }, H = "[\\x20\\t\\r\\n\\f]", B = "(?:\\\\.|[\\w-]|[^\\x00-\\xa0])+", j = B.replace("w", "w#"), F = "([*^$|!~]?=)", I = "\\[" + H + "*(" + B + ")" + H + "*(?:" + F + H + "*(?:(['\"])((?:\\\\.|[^\\\\])*?)\\3|(" + j + ")|)|)" + H + "*\\]", q = ":(" + B + ")(?:\\(((['\"])((?:\\\\.|[^\\\\])*?)\\3|((?:\\\\.|[^\\\\()[\\]]|" + I.replace(3, 8) + ")*)|.*)\\)|)", R = RegExp("^" + H + "+|((?:^|[^\\\\])(?:\\\\.)*)" + H + "+$", "g"), U = RegExp("^" + H + "*," + H + "*"), z = RegExp("^" + H + "*([\\x20\\t\\r\\n\\f>+~])" + H + "*"), W = RegExp(q), X = RegExp("^" + j + "$"), V = {
            ID: RegExp("^#(" + B + ")"),
            CLASS: RegExp("^\\.(" + B + ")"),
            NAME: RegExp("^\\[name=['\"]?(" + B + ")['\"]?\\]"),
            TAG: RegExp("^(" + B.replace("w", "w*") + ")"),
            ATTR: RegExp("^" + I),
            PSEUDO: RegExp("^" + q),
            CHILD: RegExp("^:(only|first|last|nth|nth-last)-(child|of-type)(?:\\(" + H + "*(even|odd|(([+-]|)(\\d*)n|)" + H + "*(?:([+-]|)" + H + "*(\\d+)|))" + H + "*\\)|)", "i"),
            needsContext: RegExp("^" + H + "*[>+~]|:(even|odd|eq|gt|lt|nth|first|last)(?:\\(" + H + "*((?:-\\d)?\\d*)" + H + "*\\)|)(?=[^-]|$)", "i")
        }, $ = /[\x20\t\r\n\f]*[+~]/, J = /^[^{]+\{\s*\[native code/, K = /^(?:#([\w-]+)|(\w+)|\.([\w-]+))$/, Q = /^(?:input|select|textarea|button)$/i, G = /^h\d$/i, Y = /'|\\/g, Z = /\=[\x20\t\r\n\f]*([^'"\]]*)[\x20\t\r\n\f]*\]/g, et = /\\([\da-fA-F]{1,6}[\x20\t\r\n\f]?|.)/g, tt = function (e, t) {
            var n = "0x" + t - 65536;
            return n !== n ? t : 0 > n ? String.fromCharCode(n + 65536) : String.fromCharCode(55296 | n >> 10, 56320 | 1023 & n)
        };
        try {
            D.call(E.documentElement.childNodes, 0)[0].nodeType
        } catch (nt) {
            D = function (e) {
                var t, n = [];
                while (t = this[e++])n.push(t);
                return n
            }
        }
        o = ut.isXML = function (e) {
            var t = e && (e.ownerDocument || e).documentElement;
            return t ? "HTML" !== t.nodeName : !1
        }, l = ut.setDocument = function (e) {
            var n = e ? e.ownerDocument || e : E;
            return n !== c && 9 === n.nodeType && n.documentElement ? (c = n, h = n.documentElement, p = o(n), S.tagNameNoComments = ot(function (e) {
                return e.appendChild(n.createComment("")), !e.getElementsByTagName("*").length
            }), S.attributes = ot(function (e) {
                e.innerHTML = "<select></select>";
                var t = typeof e.lastChild.getAttribute("multiple");
                return "boolean" !== t && "string" !== t
            }), S.getByClassName = ot(function (e) {
                return e.innerHTML = "<div class='hidden e'></div><div class='hidden'></div>", e.getElementsByClassName && e.getElementsByClassName("e").length ? (e.lastChild.className = "e", 2 === e.getElementsByClassName("e").length) : !1
            }), S.getByName = ot(function (e) {
                e.id = w + 0, e.innerHTML = "<a name='" + w + "'></a><div name='" + w + "'></div>", h.insertBefore(e, h.firstChild);
                var t = n.getElementsByName && n.getElementsByName(w).length === 2 + n.getElementsByName(w + 0).length;
                return S.getIdNotName = !n.getElementById(w), h.removeChild(e), t
            }), i.attrHandle = ot(function (e) {
                return e.innerHTML = "<a href='#'></a>", e.firstChild && typeof e.firstChild.getAttribute !== L && "#" === e.firstChild.getAttribute("href")
            }) ? {} : {
                href: function (e) {
                    return e.getAttribute("href", 2)
                }, type: function (e) {
                    return e.getAttribute("type")
                }
            }, S.getIdNotName ? (i.find.ID = function (e, t) {
                if (typeof t.getElementById !== L && !p) {
                    var n = t.getElementById(e);
                    return n && n.parentNode ? [n] : []
                }
            }, i.filter.ID = function (e) {
                var t = e.replace(et, tt);
                return function (e) {
                    return e.getAttribute("id") === t
                }
            }) : (i.find.ID = function (e, n) {
                if (typeof n.getElementById !== L && !p) {
                    var r = n.getElementById(e);
                    return r ? r.id === e || typeof r.getAttributeNode !== L && r.getAttributeNode("id").value === e ? [r] : t : []
                }
            }, i.filter.ID = function (e) {
                var t = e.replace(et, tt);
                return function (e) {
                    var n = typeof e.getAttributeNode !== L && e.getAttributeNode("id");
                    return n && n.value === t
                }
            }), i.find.TAG = S.tagNameNoComments ? function (e, n) {
                return typeof n.getElementsByTagName !== L ? n.getElementsByTagName(e) : t
            } : function (e, t) {
                var n, r = [], i = 0, s = t.getElementsByTagName(e);
                if ("*" === e) {
                    while (n = s[i++])1 === n.nodeType && r.push(n);
                    return r
                }
                return s
            }, i.find.NAME = S.getByName && function (e, n) {
                    return typeof n.getElementsByName !== L ? n.getElementsByName(name) : t
                }, i.find.CLASS = S.getByClassName && function (e, n) {
                    return typeof n.getElementsByClassName === L || p ? t : n.getElementsByClassName(e)
                }, v = [], d = [":focus"], (S.qsa = rt(n.querySelectorAll)) && (ot(function (e) {
                e.innerHTML = "<select><option selected=''></option></select>", e.querySelectorAll("[selected]").length || d.push("\\[" + H + "*(?:checked|disabled|ismap|multiple|readonly|selected|value)"), e.querySelectorAll(":checked").length || d.push(":checked")
            }), ot(function (e) {
                e.innerHTML = "<input type='hidden' i=''/>", e.querySelectorAll("[i^='']").length && d.push("[*^$]=" + H + "*(?:\"\"|'')"), e.querySelectorAll(":enabled").length || d.push(":enabled", ":disabled"), e.querySelectorAll("*,:x"), d.push(",.*:")
            })), (S.matchesSelector = rt(m = h.matchesSelector || h.mozMatchesSelector || h.webkitMatchesSelector || h.oMatchesSelector || h.msMatchesSelector)) && ot(function (e) {
                S.disconnectedMatch = m.call(e, "div"), m.call(e, "[s!='']:x"), v.push("!=", q)
            }), d = RegExp(d.join("|")), v = RegExp(v.join("|")), g = rt(h.contains) || h.compareDocumentPosition ? function (e, t) {
                var n = 9 === e.nodeType ? e.documentElement : e, r = t && t.parentNode;
                return e === r || !!r && 1 === r.nodeType && !!(n.contains ? n.contains(r) : e.compareDocumentPosition && 16 & e.compareDocumentPosition(r))
            } : function (e, t) {
                if (t)while (t = t.parentNode)if (t === e)return !0;
                return !1
            }, y = h.compareDocumentPosition ? function (e, t) {
                var r;
                return e === t ? (a = !0, 0) : (r = t.compareDocumentPosition && e.compareDocumentPosition && e.compareDocumentPosition(t)) ? 1 & r || e.parentNode && 11 === e.parentNode.nodeType ? e === n || g(E, e) ? -1 : t === n || g(E, t) ? 1 : 0 : 4 & r ? -1 : 1 : e.compareDocumentPosition ? -1 : 1
            } : function (e, t) {
                var r, i = 0, s = e.parentNode, o = t.parentNode, u = [e], f = [t];
                if (e === t)return a = !0, 0;
                if (!s || !o)return e === n ? -1 : t === n ? 1 : s ? -1 : o ? 1 : 0;
                if (s === o)return at(e, t);
                r = e;
                while (r = r.parentNode)u.unshift(r);
                r = t;
                while (r = r.parentNode)f.unshift(r);
                while (u[i] === f[i])i++;
                return i ? at(u[i], f[i]) : u[i] === E ? -1 : f[i] === E ? 1 : 0
            }, a = !1, [0, 0].sort(y), S.detectDuplicates = a, c) : c
        }, ut.matches = function (e, t) {
            return ut(e, null, null, t)
        }, ut.matchesSelector = function (e, t) {
            if ((e.ownerDocument || e) !== c && l(e), t = t.replace(Z, "='$1']"), !(!S.matchesSelector || p || v && v.test(t) || d.test(t)))try {
                var n = m.call(e, t);
                if (n || S.disconnectedMatch || e.document && 11 !== e.document.nodeType)return n
            } catch (r) {
            }
            return ut(t, c, null, [e]).length > 0
        }, ut.contains = function (e, t) {
            return (e.ownerDocument || e) !== c && l(e), g(e, t)
        }, ut.attr = function (e, t) {
            var n;
            return (e.ownerDocument || e) !== c && l(e), p || (t = t.toLowerCase()), (n = i.attrHandle[t]) ? n(e) : p || S.attributes ? e.getAttribute(t) : ((n = e.getAttributeNode(t)) || e.getAttribute(t)) && e[t] === !0 ? t : n && n.specified ? n.value : null
        }, ut.error = function (e) {
            throw Error("Syntax error, unrecognized expression: " + e)
        }, ut.uniqueSort = function (e) {
            var t, n = [], r = 1, i = 0;
            if (a = !S.detectDuplicates, e.sort(y), a) {
                for (; t = e[r]; r++)t === e[r - 1] && (i = n.push(r));
                while (i--)e.splice(n[i], 1)
            }
            return e
        }, s = ut.getText = function (e) {
            var t, n = "", r = 0, i = e.nodeType;
            if (i) {
                if (1 === i || 9 === i || 11 === i) {
                    if ("string" == typeof e.textContent)return e.textContent;
                    for (e = e.firstChild; e; e = e.nextSibling)n += s(e)
                } else if (3 === i || 4 === i)return e.nodeValue
            } else for (; t = e[r]; r++)n += s(t);
            return n
        }, i = ut.selectors = {
            cacheLength: 50,
            createPseudo: st,
            match: V,
            find: {},
            relative: {
                ">": {dir: "parentNode", first: !0},
                " ": {dir: "parentNode"},
                "+": {dir: "previousSibling", first: !0},
                "~": {dir: "previousSibling"}
            },
            preFilter: {
                ATTR: function (e) {
                    return e[1] = e[1].replace(et, tt), e[3] = (e[4] || e[5] || "").replace(et, tt), "~=" === e[2] && (e[3] = " " + e[3] + " "), e.slice(0, 4)
                }, CHILD: function (e) {
                    return e[1] = e[1].toLowerCase(), "nth" === e[1].slice(0, 3) ? (e[3] || ut.error(e[0]), e[4] = +(e[4] ? e[5] + (e[6] || 1) : 2 * ("even" === e[3] || "odd" === e[3])), e[5] = +(e[7] + e[8] || "odd" === e[3])) : e[3] && ut.error(e[0]), e
                }, PSEUDO: function (e) {
                    var t, n = !e[5] && e[2];
                    return V.CHILD.test(e[0]) ? null : (e[4] ? e[2] = e[4] : n && W.test(n) && (t = ht(n, !0)) && (t = n.indexOf(")", n.length - t) - n.length) && (e[0] = e[0].slice(0, t), e[2] = n.slice(0, t)), e.slice(0, 3))
                }
            },
            filter: {
                TAG: function (e) {
                    return "*" === e ? function () {
                        return !0
                    } : (e = e.replace(et, tt).toLowerCase(), function (t) {
                        return t.nodeName && t.nodeName.toLowerCase() === e
                    })
                }, CLASS: function (e) {
                    var t = N[e + " "];
                    return t || (t = RegExp("(^|" + H + ")" + e + "(" + H + "|$)")) && N(e, function (e) {
                            return t.test(e.className || typeof e.getAttribute !== L && e.getAttribute("class") || "")
                        })
                }, ATTR: function (e, t, n) {
                    return function (r) {
                        var i = ut.attr(r, e);
                        return null == i ? "!=" === t : t ? (i += "", "=" === t ? i === n : "!=" === t ? i !== n : "^=" === t ? n && 0 === i.indexOf(n) : "*=" === t ? n && i.indexOf(n) > -1 : "$=" === t ? n && i.slice(-n.length) === n : "~=" === t ? (" " + i + " ").indexOf(n) > -1 : "|=" === t ? i === n || i.slice(0, n.length + 1) === n + "-" : !1) : !0
                    }
                }, CHILD: function (e, t, n, r, i) {
                    var s = "nth" !== e.slice(0, 3), o = "last" !== e.slice(-4), u = "of-type" === t;
                    return 1 === r && 0 === i ? function (e) {
                        return !!e.parentNode
                    } : function (t, n, a) {
                        var f, l, c, h, p, d, v = s !== o ? "nextSibling" : "previousSibling", m = t.parentNode, g = u && t.nodeName.toLowerCase(), y = !a && !u;
                        if (m) {
                            if (s) {
                                while (v) {
                                    c = t;
                                    while (c = c[v])if (u ? c.nodeName.toLowerCase() === g : 1 === c.nodeType)return !1;
                                    d = v = "only" === e && !d && "nextSibling"
                                }
                                return !0
                            }
                            if (d = [o ? m.firstChild : m.lastChild], o && y) {
                                l = m[w] || (m[w] = {}), f = l[e] || [], p = f[0] === x && f[1], h = f[0] === x && f[2], c = p && m.childNodes[p];
                                while (c = ++p && c && c[v] || (h = p = 0) || d.pop())if (1 === c.nodeType && ++h && c === t) {
                                    l[e] = [x, p, h];
                                    break
                                }
                            } else if (y && (f = (t[w] || (t[w] = {}))[e]) && f[0] === x)h = f[1]; else while (c = ++p && c && c[v] || (h = p = 0) || d.pop())if ((u ? c.nodeName.toLowerCase() === g : 1 === c.nodeType) && ++h && (y && ((c[w] || (c[w] = {}))[e] = [x, h]), c === t))break;
                            return h -= i, h === r || 0 === h % r && h / r >= 0
                        }
                    }
                }, PSEUDO: function (e, t) {
                    var n, r = i.pseudos[e] || i.setFilters[e.toLowerCase()] || ut.error("unsupported pseudo: " + e);
                    return r[w] ? r(t) : r.length > 1 ? (n = [e, e, "", t], i.setFilters.hasOwnProperty(e.toLowerCase()) ? st(function (e, n) {
                        var i, s = r(e, t), o = s.length;
                        while (o--)i = P.call(e, s[o]), e[i] = !(n[i] = s[o])
                    }) : function (e) {
                        return r(e, 0, n)
                    }) : r
                }
            },
            pseudos: {
                not: st(function (e) {
                    var t = [], n = [], r = u(e.replace(R, "$1"));
                    return r[w] ? st(function (e, t, n, i) {
                        var s, o = r(e, null, i, []), u = e.length;
                        while (u--)(s = o[u]) && (e[u] = !(t[u] = s))
                    }) : function (e, i, s) {
                        return t[0] = e, r(t, null, s, n), !n.pop()
                    }
                }), has: st(function (e) {
                    return function (t) {
                        return ut(e, t).length > 0
                    }
                }), contains: st(function (e) {
                    return function (t) {
                        return (t.textContent || t.innerText || s(t)).indexOf(e) > -1
                    }
                }), lang: st(function (e) {
                    return X.test(e || "") || ut.error("unsupported lang: " + e), e = e.replace(et, tt).toLowerCase(), function (t) {
                        var n;
                        do if (n = p ? t.getAttribute("xml:lang") || t.getAttribute("lang") : t.lang)return n = n.toLowerCase(), n === e || 0 === n.indexOf(e + "-"); while ((t = t.parentNode) && 1 === t.nodeType);
                        return !1
                    }
                }), target: function (t) {
                    var n = e.location && e.location.hash;
                    return n && n.slice(1) === t.id
                }, root: function (e) {
                    return e === h
                }, focus: function (e) {
                    return e === c.activeElement && (!c.hasFocus || c.hasFocus()) && !!(e.type || e.href || ~e.tabIndex)
                }, enabled: function (e) {
                    return e.disabled === !1
                }, disabled: function (e) {
                    return e.disabled === !0
                }, checked: function (e) {
                    var t = e.nodeName.toLowerCase();
                    return "input" === t && !!e.checked || "option" === t && !!e.selected
                }, selected: function (e) {
                    return e.parentNode && e.parentNode.selectedIndex, e.selected === !0
                }, empty: function (e) {
                    for (e = e.firstChild; e; e = e.nextSibling)if (e.nodeName > "@" || 3 === e.nodeType || 4 === e.nodeType)return !1;
                    return !0
                }, parent: function (e) {
                    return !i.pseudos.empty(e)
                }, header: function (e) {
                    return G.test(e.nodeName)
                }, input: function (e) {
                    return Q.test(e.nodeName)
                }, button: function (e) {
                    var t = e.nodeName.toLowerCase();
                    return "input" === t && "button" === e.type || "button" === t
                }, text: function (e) {
                    var t;
                    return "input" === e.nodeName.toLowerCase() && "text" === e.type && (null == (t = e.getAttribute("type")) || t.toLowerCase() === e.type)
                }, first: ct(function () {
                    return [0]
                }), last: ct(function (e, t) {
                    return [t - 1]
                }), eq: ct(function (e, t, n) {
                    return [0 > n ? n + t : n]
                }), even: ct(function (e, t) {
                    var n = 0;
                    for (; t > n; n += 2)e.push(n);
                    return e
                }), odd: ct(function (e, t) {
                    var n = 1;
                    for (; t > n; n += 2)e.push(n);
                    return e
                }), lt: ct(function (e, t, n) {
                    var r = 0 > n ? n + t : n;
                    for (; --r >= 0;)e.push(r);
                    return e
                }), gt: ct(function (e, t, n) {
                    var r = 0 > n ? n + t : n;
                    for (; t > ++r;)e.push(r);
                    return e
                })
            }
        };
        for (n in{radio: !0, checkbox: !0, file: !0, password: !0, image: !0})i.pseudos[n] = ft(n);
        for (n in{submit: !0, reset: !0})i.pseudos[n] = lt(n);
        u = ut.compile = function (e, t) {
            var n, r = [], i = [], s = k[e + " "];
            if (!s) {
                t || (t = ht(e)), n = t.length;
                while (n--)s = yt(t[n]), s[w] ? r.push(s) : i.push(s);
                s = k(e, bt(i, r))
            }
            return s
        }, i.pseudos.nth = i.pseudos.eq, i.filters = St.prototype = i.pseudos, i.setFilters = new St, l(), ut.attr = b.attr, b.find = ut, b.expr = ut.selectors, b.expr[":"] = b.expr.pseudos, b.unique = ut.uniqueSort, b.text = ut.getText, b.isXMLDoc = ut.isXML, b.contains = ut.contains
    }(e);
    var ot = /Until$/, ut = /^(?:parents|prev(?:Until|All))/, at = /^.[^:#\[\.,]*$/, ft = b.expr.match.needsContext, lt = {
        children: !0,
        contents: !0,
        next: !0,
        prev: !0
    };
    b.fn.extend({
        find: function (e) {
            var t, n, r, i = this.length;
            if ("string" != typeof e)return r = this, this.pushStack(b(e).filter(function () {
                for (t = 0; i > t; t++)if (b.contains(r[t], this))return !0
            }));
            for (n = [], t = 0; i > t; t++)b.find(e, this[t], n);
            return n = this.pushStack(i > 1 ? b.unique(n) : n), n.selector = (this.selector ? this.selector + " " : "") + e, n
        }, has: function (e) {
            var t, n = b(e, this), r = n.length;
            return this.filter(function () {
                for (t = 0; r > t; t++)if (b.contains(this, n[t]))return !0
            })
        }, not: function (e) {
            return this.pushStack(ht(this, e, !1))
        }, filter: function (e) {
            return this.pushStack(ht(this, e, !0))
        }, is: function (e) {
            return !!e && ("string" == typeof e ? ft.test(e) ? b(e, this.context).index(this[0]) >= 0 : b.filter(e, this).length > 0 : this.filter(e).length > 0)
        }, closest: function (e, t) {
            var n, r = 0, i = this.length, s = [], o = ft.test(e) || "string" != typeof e ? b(e, t || this.context) : 0;
            for (; i > r; r++) {
                n = this[r];
                while (n && n.ownerDocument && n !== t && 11 !== n.nodeType) {
                    if (o ? o.index(n) > -1 : b.find.matchesSelector(n, e)) {
                        s.push(n);
                        break
                    }
                    n = n.parentNode
                }
            }
            return this.pushStack(s.length > 1 ? b.unique(s) : s)
        }, index: function (e) {
            return e ? "string" == typeof e ? b.inArray(this[0], b(e)) : b.inArray(e.jquery ? e[0] : e, this) : this[0] && this[0].parentNode ? this.first().prevAll().length : -1
        }, add: function (e, t) {
            var n = "string" == typeof e ? b(e, t) : b.makeArray(e && e.nodeType ? [e] : e), r = b.merge(this.get(), n);
            return this.pushStack(b.unique(r))
        }, addBack: function (e) {
            return this.add(null == e ? this.prevObject : this.prevObject.filter(e))
        }
    }), b.fn.andSelf = b.fn.addBack, b.each({
        parent: function (e) {
            var t = e.parentNode;
            return t && 11 !== t.nodeType ? t : null
        }, parents: function (e) {
            return b.dir(e, "parentNode")
        }, parentsUntil: function (e, t, n) {
            return b.dir(e, "parentNode", n)
        }, next: function (e) {
            return ct(e, "nextSibling")
        }, prev: function (e) {
            return ct(e, "previousSibling")
        }, nextAll: function (e) {
            return b.dir(e, "nextSibling")
        }, prevAll: function (e) {
            return b.dir(e, "previousSibling")
        }, nextUntil: function (e, t, n) {
            return b.dir(e, "nextSibling", n)
        }, prevUntil: function (e, t, n) {
            return b.dir(e, "previousSibling", n)
        }, siblings: function (e) {
            return b.sibling((e.parentNode || {}).firstChild, e)
        }, children: function (e) {
            return b.sibling(e.firstChild)
        }, contents: function (e) {
            return b.nodeName(e, "iframe") ? e.contentDocument || e.contentWindow.document : b.merge([], e.childNodes)
        }
    }, function (e, t) {
        b.fn[e] = function (n, r) {
            var i = b.map(this, t, n);
            return ot.test(e) || (r = n), r && "string" == typeof r && (i = b.filter(r, i)), i = this.length > 1 && !lt[e] ? b.unique(i) : i, this.length > 1 && ut.test(e) && (i = i.reverse()), this.pushStack(i)
        }
    }), b.extend({
        filter: function (e, t, n) {
            return n && (e = ":not(" + e + ")"), 1 === t.length ? b.find.matchesSelector(t[0], e) ? [t[0]] : [] : b.find.matches(e, t)
        }, dir: function (e, n, r) {
            var i = [], s = e[n];
            while (s && 9 !== s.nodeType && (r === t || 1 !== s.nodeType || !b(s).is(r)))1 === s.nodeType && i.push(s), s = s[n];
            return i
        }, sibling: function (e, t) {
            var n = [];
            for (; e; e = e.nextSibling)1 === e.nodeType && e !== t && n.push(e);
            return n
        }
    });
    var dt = "abbr|article|aside|audio|bdi|canvas|data|datalist|details|figcaption|figure|footer|header|hgroup|mark|meter|nav|output|progress|section|summary|time|video", vt = / jQuery\d+="(?:null|\d+)"/g, mt = RegExp("<(?:" + dt + ")[\\s/>]", "i"), gt = /^\s+/, yt = /<(?!area|br|col|embed|hr|img|input|link|meta|param)(([\w:]+)[^>]*)\/>/gi, bt = /<([\w:]+)/, wt = /<tbody/i, Et = /<|&#?\w+;/, St = /<(?:script|style|link)/i, xt = /^(?:checkbox|radio)$/i, Tt = /checked\s*(?:[^=]|=\s*.checked.)/i, Nt = /^$|\/(?:java|ecma)script/i, Ct = /^true\/(.*)/, kt = /^\s*<!(?:\[CDATA\[|--)|(?:\]\]|--)>\s*$/g, Lt = {
        option: [1, "<select multiple='multiple'>", "</select>"],
        legend: [1, "<fieldset>", "</fieldset>"],
        area: [1, "<map>", "</map>"],
        param: [1, "<object>", "</object>"],
        thead: [1, "<table>", "</table>"],
        tr: [2, "<table><tbody>", "</tbody></table>"],
        col: [2, "<table><tbody></tbody><colgroup>", "</colgroup></table>"],
        td: [3, "<table><tbody><tr>", "</tr></tbody></table>"],
        _default: b.support.htmlSerialize ? [0, "", ""] : [1, "X<div>", "</div>"]
    }, At = pt(s), Ot = At.appendChild(s.createElement("div"));
    Lt.optgroup = Lt.option, Lt.tbody = Lt.tfoot = Lt.colgroup = Lt.caption = Lt.thead, Lt.th = Lt.td, b.fn.extend({
        text: function (e) {
            return b.access(this, function (e) {
                return e === t ? b.text(this) : this.empty().append((this[0] && this[0].ownerDocument || s).createTextNode(e))
            }, null, e, arguments.length)
        }, wrapAll: function (e) {
            if (b.isFunction(e))return this.each(function (t) {
                b(this).wrapAll(e.call(this, t))
            });
            if (this[0]) {
                var t = b(e, this[0].ownerDocument).eq(0).clone(!0);
                this[0].parentNode && t.insertBefore(this[0]), t.map(function () {
                    var e = this;
                    while (e.firstChild && 1 === e.firstChild.nodeType)e = e.firstChild;
                    return e
                }).append(this)
            }
            return this
        }, wrapInner: function (e) {
            return b.isFunction(e) ? this.each(function (t) {
                b(this).wrapInner(e.call(this, t))
            }) : this.each(function () {
                var t = b(this), n = t.contents();
                n.length ? n.wrapAll(e) : t.append(e)
            })
        }, wrap: function (e) {
            var t = b.isFunction(e);
            return this.each(function (n) {
                b(this).wrapAll(t ? e.call(this, n) : e)
            })
        }, unwrap: function () {
            return this.parent().each(function () {
                b.nodeName(this, "body") || b(this).replaceWith(this.childNodes)
            }).end()
        }, append: function () {
            return this.domManip(arguments, !0, function (e) {
                (1 === this.nodeType || 11 === this.nodeType || 9 === this.nodeType) && this.appendChild(e)
            })
        }, prepend: function () {
            return this.domManip(arguments, !0, function (e) {
                (1 === this.nodeType || 11 === this.nodeType || 9 === this.nodeType) && this.insertBefore(e, this.firstChild)
            })
        }, before: function () {
            return this.domManip(arguments, !1, function (e) {
                this.parentNode && this.parentNode.insertBefore(e, this)
            })
        }, after: function () {
            return this.domManip(arguments, !1, function (e) {
                this.parentNode && this.parentNode.insertBefore(e, this.nextSibling)
            })
        }, remove: function (e, t) {
            var n, r = 0;
            for (; null != (n = this[r]); r++)(!e || b.filter(e, [n]).length > 0) && (t || 1 !== n.nodeType || b.cleanData(jt(n)), n.parentNode && (t && b.contains(n.ownerDocument, n) && Pt(jt(n, "script")), n.parentNode.removeChild(n)));
            return this
        }, empty: function () {
            var e, t = 0;
            for (; null != (e = this[t]); t++) {
                1 === e.nodeType && b.cleanData(jt(e, !1));
                while (e.firstChild)e.removeChild(e.firstChild);
                e.options && b.nodeName(e, "select") && (e.options.length = 0)
            }
            return this
        }, clone: function (e, t) {
            return e = null == e ? !1 : e, t = null == t ? e : t, this.map(function () {
                return b.clone(this, e, t)
            })
        }, html: function (e) {
            return b.access(this, function (e) {
                var n = this[0] || {}, r = 0, i = this.length;
                if (e === t)return 1 === n.nodeType ? n.innerHTML.replace(vt, "") : t;
                if (!("string" != typeof e || St.test(e) || !b.support.htmlSerialize && mt.test(e) || !b.support.leadingWhitespace && gt.test(e) || Lt[(bt.exec(e) || ["", ""])[1].toLowerCase()])) {
                    e = e.replace(yt, "<$1></$2>");
                    try {
                        for (; i > r; r++)n = this[r] || {}, 1 === n.nodeType && (b.cleanData(jt(n, !1)), n.innerHTML = e);
                        n = 0
                    } catch (s) {
                    }
                }
                n && this.empty().append(e)
            }, null, e, arguments.length)
        }, replaceWith: function (e) {
            var t = b.isFunction(e);
            return t || "string" == typeof e || (e = b(e).not(this).detach()), this.domManip([e], !0, function (e) {
                var t = this.nextSibling, n = this.parentNode;
                n && (b(this).remove(), n.insertBefore(e, t))
            })
        }, detach: function (e) {
            return this.remove(e, !0)
        }, domManip: function (e, n, r) {
            e = h.apply([], e);
            var i, s, o, u, a, f, l = 0, c = this.length, p = this, d = c - 1, v = e[0], m = b.isFunction(v);
            if (m || !(1 >= c || "string" != typeof v || b.support.checkClone) && Tt.test(v))return this.each(function (i) {
                var s = p.eq(i);
                m && (e[0] = v.call(this, i, n ? s.html() : t)), s.domManip(e, n, r)
            });
            if (c && (f = b.buildFragment(e, this[0].ownerDocument, !1, this), i = f.firstChild, 1 === f.childNodes.length && (f = i), i)) {
                for (n = n && b.nodeName(i, "tr"), u = b.map(jt(f, "script"), _t), o = u.length; c > l; l++)s = f, l !== d && (s = b.clone(s, !0, !0), o && b.merge(u, jt(s, "script"))), r.call(n && b.nodeName(this[l], "table") ? Mt(this[l], "tbody") : this[l], s, l);
                if (o)for (a = u[u.length - 1].ownerDocument, b.map(u, Dt), l = 0; o > l; l++)s = u[l], Nt.test(s.type || "") && !b._data(s, "globalEval") && b.contains(a, s) && (s.src ? b.ajax({
                    url: s.src,
                    type: "GET",
                    dataType: "script",
                    async: !1,
                    global: !1,
                    "throws": !0
                }) : b.globalEval((s.text || s.textContent || s.innerHTML || "").replace(kt, "")));
                f = i = null
            }
            return this
        }
    }), b.each({
        appendTo: "append",
        prependTo: "prepend",
        insertBefore: "before",
        insertAfter: "after",
        replaceAll: "replaceWith"
    }, function (e, t) {
        b.fn[e] = function (e) {
            var n, r = 0, i = [], s = b(e), o = s.length - 1;
            for (; o >= r; r++)n = r === o ? this : this.clone(!0), b(s[r])[t](n), p.apply(i, n.get());
            return this.pushStack(i)
        }
    }), b.extend({
        clone: function (e, t, n) {
            var r, i, s, o, u, a = b.contains(e.ownerDocument, e);
            if (b.support.html5Clone || b.isXMLDoc(e) || !mt.test("<" + e.nodeName + ">") ? s = e.cloneNode(!0) : (Ot.innerHTML = e.outerHTML, Ot.removeChild(s = Ot.firstChild)), !(b.support.noCloneEvent && b.support.noCloneChecked || 1 !== e.nodeType && 11 !== e.nodeType || b.isXMLDoc(e)))for (r = jt(s), u = jt(e), o = 0; null != (i = u[o]); ++o)r[o] && Bt(i, r[o]);
            if (t)if (n)for (u = u || jt(e), r = r || jt(s), o = 0; null != (i = u[o]); o++)Ht(i, r[o]); else Ht(e, s);
            return r = jt(s, "script"), r.length > 0 && Pt(r, !a && jt(e, "script")), r = u = i = null, s
        }, buildFragment: function (e, t, n, r) {
            var i, s, o, u, a, f, l, c = e.length, h = pt(t), p = [], d = 0;
            for (; c > d; d++)if (s = e[d], s || 0 === s)if ("object" === b.type(s))b.merge(p, s.nodeType ? [s] : s); else if (Et.test(s)) {
                u = u || h.appendChild(t.createElement("div")), a = (bt.exec(s) || ["", ""])[1].toLowerCase(), l = Lt[a] || Lt._default, u.innerHTML = l[1] + s.replace(yt, "<$1></$2>") + l[2], i = l[0];
                while (i--)u = u.lastChild;
                if (!b.support.leadingWhitespace && gt.test(s) && p.push(t.createTextNode(gt.exec(s)[0])), !b.support.tbody) {
                    s = "table" !== a || wt.test(s) ? "<table>" !== l[1] || wt.test(s) ? 0 : u : u.firstChild, i = s && s.childNodes.length;
                    while (i--)b.nodeName(f = s.childNodes[i], "tbody") && !f.childNodes.length && s.removeChild(f)
                }
                b.merge(p, u.childNodes), u.textContent = "";
                while (u.firstChild)u.removeChild(u.firstChild);
                u = h.lastChild
            } else p.push(t.createTextNode(s));
            u && h.removeChild(u), b.support.appendChecked || b.grep(jt(p, "input"), Ft), d = 0;
            while (s = p[d++])if ((!r || -1 === b.inArray(s, r)) && (o = b.contains(s.ownerDocument, s), u = jt(h.appendChild(s), "script"), o && Pt(u), n)) {
                i = 0;
                while (s = u[i++])Nt.test(s.type || "") && n.push(s)
            }
            return u = null, h
        }, cleanData: function (e, t) {
            var n, r, s, o, u = 0, a = b.expando, f = b.cache, c = b.support.deleteExpando, h = b.event.special;
            for (; null != (n = e[u]); u++)if ((t || b.acceptData(n)) && (s = n[a], o = s && f[s])) {
                if (o.events)for (r in o.events)h[r] ? b.event.remove(n, r) : b.removeEvent(n, r, o.handle);
                f[s] && (delete f[s], c ? delete n[a] : typeof n.removeAttribute !== i ? n.removeAttribute(a) : n[a] = null, l.push(s))
            }
        }
    });
    var It, qt, Rt, Ut = /alpha\([^)]*\)/i, zt = /opacity\s*=\s*([^)]*)/, Wt = /^(top|right|bottom|left)$/, Xt = /^(none|table(?!-c[ea]).+)/, Vt = /^margin/, $t = RegExp("^(" + w + ")(.*)$", "i"), Jt = RegExp("^(" + w + ")(?!px)[a-z%]+$", "i"), Kt = RegExp("^([+-])=(" + w + ")", "i"), Qt = {BODY: "block"}, Gt = {
        position: "absolute",
        visibility: "hidden",
        display: "block"
    }, Yt = {
        letterSpacing: 0,
        fontWeight: 400
    }, Zt = ["Top", "Right", "Bottom", "Left"], en = ["Webkit", "O", "Moz", "ms"];
    b.fn.extend({
        css: function (e, n) {
            return b.access(this, function (e, n, r) {
                var i, s, o = {}, u = 0;
                if (b.isArray(n)) {
                    for (s = qt(e), i = n.length; i > u; u++)o[n[u]] = b.css(e, n[u], !1, s);
                    return o
                }
                return r !== t ? b.style(e, n, r) : b.css(e, n)
            }, e, n, arguments.length > 1)
        }, show: function () {
            return rn(this, !0)
        }, hide: function () {
            return rn(this)
        }, toggle: function (e) {
            var t = "boolean" == typeof e;
            return this.each(function () {
                (t ? e : nn(this)) ? b(this).show() : b(this).hide()
            })
        }
    }), b.extend({
        cssHooks: {
            opacity: {
                get: function (e, t) {
                    if (t) {
                        var n = Rt(e, "opacity");
                        return "" === n ? "1" : n
                    }
                }
            }
        },
        cssNumber: {
            columnCount: !0,
            fillOpacity: !0,
            fontWeight: !0,
            lineHeight: !0,
            opacity: !0,
            orphans: !0,
            widows: !0,
            zIndex: !0,
            zoom: !0
        },
        cssProps: {"float": b.support.cssFloat ? "cssFloat" : "styleFloat"},
        style: function (e, n, r, i) {
            if (e && 3 !== e.nodeType && 8 !== e.nodeType && e.style) {
                var s, o, u, a = b.camelCase(n), f = e.style;
                if (n = b.cssProps[a] || (b.cssProps[a] = tn(f, a)), u = b.cssHooks[n] || b.cssHooks[a], r === t)return u && "get"in u && (s = u.get(e, !1, i)) !== t ? s : f[n];
                if (o = typeof r, "string" === o && (s = Kt.exec(r)) && (r = (s[1] + 1) * s[2] + parseFloat(b.css(e, n)), o = "number"), !(null == r || "number" === o && isNaN(r) || ("number" !== o || b.cssNumber[a] || (r += "px"), b.support.clearCloneStyle || "" !== r || 0 !== n.indexOf("background") || (f[n] = "inherit"), u && "set"in u && (r = u.set(e, r, i)) === t)))try {
                    f[n] = r
                } catch (l) {
                }
            }
        },
        css: function (e, n, r, i) {
            var s, o, u, a = b.camelCase(n);
            return n = b.cssProps[a] || (b.cssProps[a] = tn(e.style, a)), u = b.cssHooks[n] || b.cssHooks[a], u && "get"in u && (o = u.get(e, !0, r)), o === t && (o = Rt(e, n, i)), "normal" === o && n in Yt && (o = Yt[n]), "" === r || r ? (s = parseFloat(o), r === !0 || b.isNumeric(s) ? s || 0 : o) : o
        },
        swap: function (e, t, n, r) {
            var i, s, o = {};
            for (s in t)o[s] = e.style[s], e.style[s] = t[s];
            i = n.apply(e, r || []);
            for (s in t)e.style[s] = o[s];
            return i
        }
    }), e.getComputedStyle ? (qt = function (t) {
        return e.getComputedStyle(t, null)
    }, Rt = function (e, n, r) {
        var i, s, o, u = r || qt(e), a = u ? u.getPropertyValue(n) || u[n] : t, f = e.style;
        return u && ("" !== a || b.contains(e.ownerDocument, e) || (a = b.style(e, n)), Jt.test(a) && Vt.test(n) && (i = f.width, s = f.minWidth, o = f.maxWidth, f.minWidth = f.maxWidth = f.width = a, a = u.width, f.width = i, f.minWidth = s, f.maxWidth = o)), a
    }) : s.documentElement.currentStyle && (qt = function (e) {
        return e.currentStyle
    }, Rt = function (e, n, r) {
        var i, s, o, u = r || qt(e), a = u ? u[n] : t, f = e.style;
        return null == a && f && f[n] && (a = f[n]), Jt.test(a) && !Wt.test(n) && (i = f.left, s = e.runtimeStyle, o = s && s.left, o && (s.left = e.currentStyle.left), f.left = "fontSize" === n ? "1em" : a, a = f.pixelLeft + "px", f.left = i, o && (s.left = o)), "" === a ? "auto" : a
    }), b.each(["height", "width"], function (e, n) {
        b.cssHooks[n] = {
            get: function (e, r, i) {
                return r ? 0 === e.offsetWidth && Xt.test(b.css(e, "display")) ? b.swap(e, Gt, function () {
                    return un(e, n, i)
                }) : un(e, n, i) : t
            }, set: function (e, t, r) {
                var i = r && qt(e);
                return sn(e, t, r ? on(e, n, r, b.support.boxSizing && "border-box" === b.css(e, "boxSizing", !1, i), i) : 0)
            }
        }
    }), b.support.opacity || (b.cssHooks.opacity = {
        get: function (e, t) {
            return zt.test((t && e.currentStyle ? e.currentStyle.filter : e.style.filter) || "") ? .01 * parseFloat(RegExp.$1) + "" : t ? "1" : ""
        }, set: function (e, t) {
            var n = e.style, r = e.currentStyle, i = b.isNumeric(t) ? "alpha(opacity=" + 100 * t + ")" : "", s = r && r.filter || n.filter || "";
            n.zoom = 1, (t >= 1 || "" === t) && "" === b.trim(s.replace(Ut, "")) && n.removeAttribute && (n.removeAttribute("filter"), "" === t || r && !r.filter) || (n.filter = Ut.test(s) ? s.replace(Ut, i) : s + " " + i)
        }
    }), b(function () {
        b.support.reliableMarginRight || (b.cssHooks.marginRight = {
            get: function (e, n) {
                return n ? b.swap(e, {display: "inline-block"}, Rt, [e, "marginRight"]) : t
            }
        }), !b.support.pixelPosition && b.fn.position && b.each(["top", "left"], function (e, n) {
            b.cssHooks[n] = {
                get: function (e, r) {
                    return r ? (r = Rt(e, n), Jt.test(r) ? b(e).position()[n] + "px" : r) : t
                }
            }
        })
    }), b.expr && b.expr.filters && (b.expr.filters.hidden = function (e) {
        return 0 >= e.offsetWidth && 0 >= e.offsetHeight || !b.support.reliableHiddenOffsets && "none" === (e.style && e.style.display || b.css(e, "display"))
    }, b.expr.filters.visible = function (e) {
        return !b.expr.filters.hidden(e)
    }), b.each({margin: "", padding: "", border: "Width"}, function (e, t) {
        b.cssHooks[e + t] = {
            expand: function (n) {
                var r = 0, i = {}, s = "string" == typeof n ? n.split(" ") : [n];
                for (; 4 > r; r++)i[e + Zt[r] + t] = s[r] || s[r - 2] || s[0];
                return i
            }
        }, Vt.test(e) || (b.cssHooks[e + t].set = sn)
    });
    var ln = /%20/g, cn = /\[\]$/, hn = /\r?\n/g, pn = /^(?:submit|button|image|reset|file)$/i, dn = /^(?:input|select|textarea|keygen)/i;
    b.fn.extend({
        serialize: function () {
            return b.param(this.serializeArray())
        }, serializeArray: function () {
            return this.map(function () {
                var e = b.prop(this, "elements");
                return e ? b.makeArray(e) : this
            }).filter(function () {
                var e = this.type;
                return this.name && !b(this).is(":disabled") && dn.test(this.nodeName) && !pn.test(e) && (this.checked || !xt.test(e))
            }).map(function (e, t) {
                var n = b(this).val();
                return null == n ? null : b.isArray(n) ? b.map(n, function (e) {
                    return {name: t.name, value: e.replace(hn, "\r\n")}
                }) : {name: t.name, value: n.replace(hn, "\r\n")}
            }).get()
        }
    }), b.param = function (e, n) {
        var r, i = [], s = function (e, t) {
            t = b.isFunction(t) ? t() : null == t ? "" : t, i[i.length] = encodeURIComponent(e) + "=" + encodeURIComponent(t)
        };
        if (n === t && (n = b.ajaxSettings && b.ajaxSettings.traditional), b.isArray(e) || e.jquery && !b.isPlainObject(e))b.each(e, function () {
            s(this.name, this.value)
        }); else for (r in e)vn(r, e[r], n, s);
        return i.join("&").replace(ln, "+")
    }, b.each("blur focus focusin focusout load resize scroll unload click dblclick mousedown mouseup mousemove mouseover mouseout mouseenter mouseleave change select submit keydown keypress keyup error contextmenu".split(" "), function (e, t) {
        b.fn[t] = function (e, n) {
            return arguments.length > 0 ? this.on(t, null, e, n) : this.trigger(t)
        }
    }), b.fn.hover = function (e, t) {
        return this.mouseenter(e).mouseleave(t || e)
    };
    var mn, gn, yn = b.now(), bn = /\?/, wn = /#.*$/, En = /([?&])_=[^&]*/, Sn = /^(.*?):[ \t]*([^\r\n]*)\r?$/gm, xn = /^(?:about|app|app-storage|.+-extension|file|res|widget):$/, Tn = /^(?:GET|HEAD)$/, Nn = /^\/\//, Cn = /^([\w.+-]+:)(?:\/\/([^\/?#:]*)(?::(\d+)|)|)/, kn = b.fn.load, Ln = {}, An = {}, On = "*/".concat("*");
    try {
        gn = o.href
    } catch (Mn) {
        gn = s.createElement("a"), gn.href = "", gn = gn.href
    }
    mn = Cn.exec(gn.toLowerCase()) || [], b.fn.load = function (e, n, r) {
        if ("string" != typeof e && kn)return kn.apply(this, arguments);
        var i, s, o, u = this, a = e.indexOf(" ");
        return a >= 0 && (i = e.slice(a, e.length), e = e.slice(0, a)), b.isFunction(n) ? (r = n, n = t) : n && "object" == typeof n && (o = "POST"), u.length > 0 && b.ajax({
            url: e,
            type: o,
            dataType: "html",
            data: n
        }).done(function (e) {
            s = arguments, u.html(i ? b("<div>").append(b.parseHTML(e)).find(i) : e)
        }).complete(r && function (e, t) {
                u.each(r, s || [e.responseText, t, e])
            }), this
    }, b.each(["ajaxStart", "ajaxStop", "ajaxComplete", "ajaxError", "ajaxSuccess", "ajaxSend"], function (e, t) {
        b.fn[t] = function (e) {
            return this.on(t, e)
        }
    }), b.each(["get", "post"], function (e, n) {
        b[n] = function (e, r, i, s) {
            return b.isFunction(r) && (s = s || i, i = r, r = t), b.ajax({
                url: e,
                type: n,
                dataType: s,
                data: r,
                success: i
            })
        }
    }), b.extend({
        active: 0,
        lastModified: {},
        etag: {},
        ajaxSettings: {
            url: gn,
            type: "GET",
            isLocal: xn.test(mn[1]),
            global: !0,
            processData: !0,
            async: !0,
            contentType: "application/x-www-form-urlencoded; charset=UTF-8",
            accepts: {
                "*": On,
                text: "text/plain",
                html: "text/html",
                xml: "application/xml, text/xml",
                json: "application/json, text/javascript"
            },
            contents: {xml: /xml/, html: /html/, json: /json/},
            responseFields: {xml: "responseXML", text: "responseText"},
            converters: {"* text": e.String, "text html": !0, "text json": b.parseJSON, "text xml": b.parseXML},
            flatOptions: {url: !0, context: !0}
        },
        ajaxSetup: function (e, t) {
            return t ? Pn(Pn(e, b.ajaxSettings), t) : Pn(b.ajaxSettings, e)
        },
        ajaxPrefilter: _n(Ln),
        ajaxTransport: _n(An),
        ajax: function (e, n) {
            function N(e, n, r, i) {
                var l, g, y, E, S, T = n;
                2 !== w && (w = 2, u && clearTimeout(u), f = t, o = i || "", x.readyState = e > 0 ? 4 : 0, r && (E = Hn(c, x, r)), e >= 200 && 300 > e || 304 === e ? (c.ifModified && (S = x.getResponseHeader("Last-Modified"), S && (b.lastModified[s] = S), S = x.getResponseHeader("etag"), S && (b.etag[s] = S)), 204 === e ? (l = !0, T = "nocontent") : 304 === e ? (l = !0, T = "notmodified") : (l = Bn(c, E), T = l.state, g = l.data, y = l.error, l = !y)) : (y = T, (e || !T) && (T = "error", 0 > e && (e = 0))), x.status = e, x.statusText = (n || T) + "", l ? d.resolveWith(h, [g, T, x]) : d.rejectWith(h, [x, T, y]), x.statusCode(m), m = t, a && p.trigger(l ? "ajaxSuccess" : "ajaxError", [x, c, l ? g : y]), v.fireWith(h, [x, T]), a && (p.trigger("ajaxComplete", [x, c]), --b.active || b.event.trigger("ajaxStop")))
            }

            "object" == typeof e && (n = e, e = t), n = n || {};
            var r, i, s, o, u, a, f, l, c = b.ajaxSetup({}, n), h = c.context || c, p = c.context && (h.nodeType || h.jquery) ? b(h) : b.event, d = b.Deferred(), v = b.Callbacks("once memory"), m = c.statusCode || {}, g = {}, y = {}, w = 0, S = "canceled", x = {
                readyState: 0,
                getResponseHeader: function (e) {
                    var t;
                    if (2 === w) {
                        if (!l) {
                            l = {};
                            while (t = Sn.exec(o))l[t[1].toLowerCase()] = t[2]
                        }
                        t = l[e.toLowerCase()]
                    }
                    return null == t ? null : t
                },
                getAllResponseHeaders: function () {
                    return 2 === w ? o : null
                },
                setRequestHeader: function (e, t) {
                    var n = e.toLowerCase();
                    return w || (e = y[n] = y[n] || e, g[e] = t), this
                },
                overrideMimeType: function (e) {
                    return w || (c.mimeType = e), this
                },
                statusCode: function (e) {
                    var t;
                    if (e)if (2 > w)for (t in e)m[t] = [m[t], e[t]]; else x.always(e[x.status]);
                    return this
                },
                abort: function (e) {
                    var t = e || S;
                    return f && f.abort(t), N(0, t), this
                }
            };
            if (d.promise(x).complete = v.add, x.success = x.done, x.error = x.fail, c.url = ((e || c.url || gn) + "").replace(wn, "").replace(Nn, mn[1] + "//"), c.type = n.method || n.type || c.method || c.type, c.dataTypes = b.trim(c.dataType || "*").toLowerCase().match(E) || [""], null == c.crossDomain && (r = Cn.exec(c.url.toLowerCase()), c.crossDomain = !(!r || r[1] === mn[1] && r[2] === mn[2] && (r[3] || ("http:" === r[1] ? 80 : 443)) == (mn[3] || ("http:" === mn[1] ? 80 : 443)))), c.data && c.processData && "string" != typeof c.data && (c.data = b.param(c.data, c.traditional)), Dn(Ln, c, n, x), 2 === w)return x;
            a = c.global, a && 0 === b.active++ && b.event.trigger("ajaxStart"), c.type = c.type.toUpperCase(), c.hasContent = !Tn.test(c.type), s = c.url, c.hasContent || (c.data && (s = c.url += (bn.test(s) ? "&" : "?") + c.data, delete c.data), c.cache === !1 && (c.url = En.test(s) ? s.replace(En, "$1_=" + yn++) : s + (bn.test(s) ? "&" : "?") + "_=" + yn++)), c.ifModified && (b.lastModified[s] && x.setRequestHeader("If-Modified-Since", b.lastModified[s]), b.etag[s] && x.setRequestHeader("If-None-Match", b.etag[s])), (c.data && c.hasContent && c.contentType !== !1 || n.contentType) && x.setRequestHeader("Content-Type", c.contentType), x.setRequestHeader("Accept", c.dataTypes[0] && c.accepts[c.dataTypes[0]] ? c.accepts[c.dataTypes[0]] + ("*" !== c.dataTypes[0] ? ", " + On + "; q=0.01" : "") : c.accepts["*"]);
            for (i in c.headers)x.setRequestHeader(i, c.headers[i]);
            if (!c.beforeSend || c.beforeSend.call(h, x, c) !== !1 && 2 !== w) {
                S = "abort";
                for (i in{success: 1, error: 1, complete: 1})x[i](c[i]);
                if (f = Dn(An, c, n, x)) {
                    x.readyState = 1, a && p.trigger("ajaxSend", [x, c]), c.async && c.timeout > 0 && (u = setTimeout(function () {
                        x.abort("timeout")
                    }, c.timeout));
                    try {
                        w = 1, f.send(g, N)
                    } catch (T) {
                        if (!(2 > w))throw T;
                        N(-1, T)
                    }
                } else N(-1, "No Transport");
                return x
            }
            return x.abort()
        },
        getScript: function (e, n) {
            return b.get(e, t, n, "script")
        },
        getJSON: function (e, t, n) {
            return b.get(e, t, n, "json")
        }
    }), b.ajaxSetup({
        accepts: {script: "text/javascript, application/javascript, application/ecmascript, application/x-ecmascript"},
        contents: {script: /(?:java|ecma)script/},
        converters: {
            "text script": function (e) {
                return b.globalEval(e), e
            }
        }
    }), b.ajaxPrefilter("script", function (e) {
        e.cache === t && (e.cache = !1), e.crossDomain && (e.type = "GET", e.global = !1)
    }), b.ajaxTransport("script", function (e) {
        if (e.crossDomain) {
            var n, r = s.head || b("head")[0] || s.documentElement;
            return {
                send: function (t, i) {
                    n = s.createElement("script"), n.async = !0, e.scriptCharset && (n.charset = e.scriptCharset), n.src = e.url, n.onload = n.onreadystatechange = function (e, t) {
                        (t || !n.readyState || /loaded|complete/.test(n.readyState)) && (n.onload = n.onreadystatechange = null, n.parentNode && n.parentNode.removeChild(n), n = null, t || i(200, "success"))
                    }, r.insertBefore(n, r.firstChild)
                }, abort: function () {
                    n && n.onload(t, !0)
                }
            }
        }
    });
    var jn = [], Fn = /(=)\?(?=&|$)|\?\?/;
    b.ajaxSetup({
        jsonp: "callback", jsonpCallback: function () {
            var e = jn.pop() || b.expando + "_" + yn++;
            return this[e] = !0, e
        }
    }), b.ajaxPrefilter("json jsonp", function (n, r, i) {
        var s, o, u, a = n.jsonp !== !1 && (Fn.test(n.url) ? "url" : "string" == typeof n.data && !(n.contentType || "").indexOf("application/x-www-form-urlencoded") && Fn.test(n.data) && "data");
        return a || "jsonp" === n.dataTypes[0] ? (s = n.jsonpCallback = b.isFunction(n.jsonpCallback) ? n.jsonpCallback() : n.jsonpCallback, a ? n[a] = n[a].replace(Fn, "$1" + s) : n.jsonp !== !1 && (n.url += (bn.test(n.url) ? "&" : "?") + n.jsonp + "=" + s), n.converters["script json"] = function () {
            return u || b.error(s + " was not called"), u[0]
        }, n.dataTypes[0] = "json", o = e[s], e[s] = function () {
            u = arguments
        }, i.always(function () {
            e[s] = o, n[s] && (n.jsonpCallback = r.jsonpCallback, jn.push(s)), u && b.isFunction(o) && o(u[0]), u = o = t
        }), "script") : t
    });
    var In, qn, Rn = 0, Un = e.ActiveXObject && function () {
            var e;
            for (e in In)In[e](t, !0)
        };
    b.ajaxSettings.xhr = e.ActiveXObject ? function () {
        return !this.isLocal && zn() || Wn()
    } : zn, qn = b.ajaxSettings.xhr(), b.support.cors = !!qn && "withCredentials"in qn, qn = b.support.ajax = !!qn, qn && b.ajaxTransport(function (n) {
        if (!n.crossDomain || b.support.cors) {
            var r;
            return {
                send: function (i, s) {
                    var o, u, a = n.xhr();
                    if (n.username ? a.open(n.type, n.url, n.async, n.username, n.password) : a.open(n.type, n.url, n.async), n.xhrFields)for (u in n.xhrFields)a[u] = n.xhrFields[u];
                    n.mimeType && a.overrideMimeType && a.overrideMimeType(n.mimeType), n.crossDomain || i["X-Requested-With"] || (i["X-Requested-With"] = "XMLHttpRequest");
                    try {
                        for (u in i)a.setRequestHeader(u, i[u])
                    } catch (f) {
                    }
                    a.send(n.hasContent && n.data || null), r = function (e, i) {
                        var u, f, l, c;
                        try {
                            if (r && (i || 4 === a.readyState))if (r = t, o && (a.onreadystatechange = b.noop, Un && delete In[o]), i)4 !== a.readyState && a.abort(); else {
                                c = {}, u = a.status, f = a.getAllResponseHeaders(), "string" == typeof a.responseText && (c.text = a.responseText);
                                try {
                                    l = a.statusText
                                } catch (h) {
                                    l = ""
                                }
                                u || !n.isLocal || n.crossDomain ? 1223 === u && (u = 204) : u = c.text ? 200 : 404
                            }
                        } catch (p) {
                            i || s(-1, p)
                        }
                        c && s(u, l, c, f)
                    }, n.async ? 4 === a.readyState ? setTimeout(r) : (o = ++Rn, Un && (In || (In = {}, b(e).unload(Un)), In[o] = r), a.onreadystatechange = r) : r()
                }, abort: function () {
                    r && r(t, !0)
                }
            }
        }
    });
    var Xn, Vn, $n = /^(?:toggle|show|hide)$/, Jn = RegExp("^(?:([+-])=|)(" + w + ")([a-z%]*)$", "i"), Kn = /queueHooks$/, Qn = [nr], Gn = {
        "*": [function (e, t) {
            var n, r, i = this.createTween(e, t), s = Jn.exec(t), o = i.cur(), u = +o || 0, a = 1, f = 20;
            if (s) {
                if (n = +s[2], r = s[3] || (b.cssNumber[e] ? "" : "px"), "px" !== r && u) {
                    u = b.css(i.elem, e, !0) || n || 1;
                    do a = a || ".5", u /= a, b.style(i.elem, e, u + r); while (a !== (a = i.cur() / o) && 1 !== a && --f)
                }
                i.unit = r, i.start = u, i.end = s[1] ? u + (s[1] + 1) * n : n
            }
            return i
        }]
    };
    b.Animation = b.extend(er, {
        tweener: function (e, t) {
            b.isFunction(e) ? (t = e, e = ["*"]) : e = e.split(" ");
            var n, r = 0, i = e.length;
            for (; i > r; r++)n = e[r], Gn[n] = Gn[n] || [], Gn[n].unshift(t)
        }, prefilter: function (e, t) {
            t ? Qn.unshift(e) : Qn.push(e)
        }
    }), b.Tween = rr, rr.prototype = {
        constructor: rr, init: function (e, t, n, r, i, s) {
            this.elem = e, this.prop = n, this.easing = i || "swing", this.options = t, this.start = this.now = this.cur(), this.end = r, this.unit = s || (b.cssNumber[n] ? "" : "px")
        }, cur: function () {
            var e = rr.propHooks[this.prop];
            return e && e.get ? e.get(this) : rr.propHooks._default.get(this)
        }, run: function (e) {
            var t, n = rr.propHooks[this.prop];
            return this.pos = t = this.options.duration ? b.easing[this.easing](e, this.options.duration * e, 0, 1, this.options.duration) : e, this.now = (this.end - this.start) * t + this.start, this.options.step && this.options.step.call(this.elem, this.now, this), n && n.set ? n.set(this) : rr.propHooks._default.set(this), this
        }
    }, rr.prototype.init.prototype = rr.prototype, rr.propHooks = {
        _default: {
            get: function (e) {
                var t;
                return null == e.elem[e.prop] || e.elem.style && null != e.elem.style[e.prop] ? (t = b.css(e.elem, e.prop, ""), t && "auto" !== t ? t : 0) : e.elem[e.prop]
            }, set: function (e) {
                b.fx.step[e.prop] ? b.fx.step[e.prop](e) : e.elem.style && (null != e.elem.style[b.cssProps[e.prop]] || b.cssHooks[e.prop]) ? b.style(e.elem, e.prop, e.now + e.unit) : e.elem[e.prop] = e.now
            }
        }
    }, rr.propHooks.scrollTop = rr.propHooks.scrollLeft = {
        set: function (e) {
            e.elem.nodeType && e.elem.parentNode && (e.elem[e.prop] = e.now)
        }
    }, b.each(["toggle", "show", "hide"], function (e, t) {
        var n = b.fn[t];
        b.fn[t] = function (e, r, i) {
            return null == e || "boolean" == typeof e ? n.apply(this, arguments) : this.animate(ir(t, !0), e, r, i)
        }
    }), b.fn.extend({
        fadeTo: function (e, t, n, r) {
            return this.filter(nn).css("opacity", 0).show().end().animate({opacity: t}, e, n, r)
        }, animate: function (e, t, n, r) {
            var i = b.isEmptyObject(e), s = b.speed(t, n, r), o = function () {
                var t = er(this, b.extend({}, e), s);
                o.finish = function () {
                    t.stop(!0)
                }, (i || b._data(this, "finish")) && t.stop(!0)
            };
            return o.finish = o, i || s.queue === !1 ? this.each(o) : this.queue(s.queue, o)
        }, stop: function (e, n, r) {
            var i = function (e) {
                var t = e.stop;
                delete e.stop, t(r)
            };
            return "string" != typeof e && (r = n, n = e, e = t), n && e !== !1 && this.queue(e || "fx", []), this.each(function () {
                var t = !0, n = null != e && e + "queueHooks", s = b.timers, o = b._data(this);
                if (n)o[n] && o[n].stop && i(o[n]); else for (n in o)o[n] && o[n].stop && Kn.test(n) && i(o[n]);
                for (n = s.length; n--;)s[n].elem !== this || null != e && s[n].queue !== e || (s[n].anim.stop(r), t = !1, s.splice(n, 1));
                (t || !r) && b.dequeue(this, e)
            })
        }, finish: function (e) {
            return e !== !1 && (e = e || "fx"), this.each(function () {
                var t, n = b._data(this), r = n[e + "queue"], i = n[e + "queueHooks"], s = b.timers, o = r ? r.length : 0;
                for (n.finish = !0, b.queue(this, e, []), i && i.cur && i.cur.finish && i.cur.finish.call(this), t = s.length; t--;)s[t].elem === this && s[t].queue === e && (s[t].anim.stop(!0), s.splice(t, 1));
                for (t = 0; o > t; t++)r[t] && r[t].finish && r[t].finish.call(this);
                delete n.finish
            })
        }
    }), b.each({
        slideDown: ir("show"),
        slideUp: ir("hide"),
        slideToggle: ir("toggle"),
        fadeIn: {opacity: "show"},
        fadeOut: {opacity: "hide"},
        fadeToggle: {opacity: "toggle"}
    }, function (e, t) {
        b.fn[e] = function (e, n, r) {
            return this.animate(t, e, n, r)
        }
    }), b.speed = function (e, t, n) {
        var r = e && "object" == typeof e ? b.extend({}, e) : {
            complete: n || !n && t || b.isFunction(e) && e,
            duration: e,
            easing: n && t || t && !b.isFunction(t) && t
        };
        return r.duration = b.fx.off ? 0 : "number" == typeof r.duration ? r.duration : r.duration in b.fx.speeds ? b.fx.speeds[r.duration] : b.fx.speeds._default, (null == r.queue || r.queue === !0) && (r.queue = "fx"), r.old = r.complete, r.complete = function () {
            b.isFunction(r.old) && r.old.call(this), r.queue && b.dequeue(this, r.queue)
        }, r
    }, b.easing = {
        linear: function (e) {
            return e
        }, swing: function (e) {
            return .5 - Math.cos(e * Math.PI) / 2
        }
    }, b.timers = [], b.fx = rr.prototype.init, b.fx.tick = function () {
        var e, n = b.timers, r = 0;
        for (Xn = b.now(); n.length > r; r++)e = n[r], e() || n[r] !== e || n.splice(r--, 1);
        n.length || b.fx.stop(), Xn = t
    }, b.fx.timer = function (e) {
        e() && b.timers.push(e) && b.fx.start()
    }, b.fx.interval = 13, b.fx.start = function () {
        Vn || (Vn = setInterval(b.fx.tick, b.fx.interval))
    }, b.fx.stop = function () {
        clearInterval(Vn), Vn = null
    }, b.fx.speeds = {
        slow: 600,
        fast: 200,
        _default: 400
    }, b.fx.step = {}, b.expr && b.expr.filters && (b.expr.filters.animated = function (e) {
        return b.grep(b.timers, function (t) {
            return e === t.elem
        }).length
    }), b.fn.offset = function (e) {
        if (arguments.length)return e === t ? this : this.each(function (t) {
            b.offset.setOffset(this, e, t)
        });
        var n, r, s = {top: 0, left: 0}, o = this[0], u = o && o.ownerDocument;
        if (u)return n = u.documentElement, b.contains(n, o) ? (typeof o.getBoundingClientRect !== i && (s = o.getBoundingClientRect()), r = sr(u), {
            top: s.top + (r.pageYOffset || n.scrollTop) - (n.clientTop || 0),
            left: s.left + (r.pageXOffset || n.scrollLeft) - (n.clientLeft || 0)
        }) : s
    }, b.offset = {
        setOffset: function (e, t, n) {
            var r = b.css(e, "position");
            "static" === r && (e.style.position = "relative");
            var i = b(e), s = i.offset(), o = b.css(e, "top"), u = b.css(e, "left"), a = ("absolute" === r || "fixed" === r) && b.inArray("auto", [o, u]) > -1, f = {}, l = {}, c, h;
            a ? (l = i.position(), c = l.top, h = l.left) : (c = parseFloat(o) || 0, h = parseFloat(u) || 0), b.isFunction(t) && (t = t.call(e, n, s)), null != t.top && (f.top = t.top - s.top + c), null != t.left && (f.left = t.left - s.left + h), "using"in t ? t.using.call(e, f) : i.css(f)
        }
    }, b.fn.extend({
        position: function () {
            if (this[0]) {
                var e, t, n = {top: 0, left: 0}, r = this[0];
                return "fixed" === b.css(r, "position") ? t = r.getBoundingClientRect() : (e = this.offsetParent(), t = this.offset(), b.nodeName(e[0], "html") || (n = e.offset()), n.top += b.css(e[0], "borderTopWidth", !0), n.left += b.css(e[0], "borderLeftWidth", !0)), {
                    top: t.top - n.top - b.css(r, "marginTop", !0),
                    left: t.left - n.left - b.css(r, "marginLeft", !0)
                }
            }
        }, offsetParent: function () {
            return this.map(function () {
                var e = this.offsetParent || s.documentElement;
                while (e && !b.nodeName(e, "html") && "static" === b.css(e, "position"))e = e.offsetParent;
                return e || s.documentElement
            })
        }
    }), b.each({scrollLeft: "pageXOffset", scrollTop: "pageYOffset"}, function (e, n) {
        var r = /Y/.test(n);
        b.fn[e] = function (i) {
            return b.access(this, function (e, i, s) {
                var o = sr(e);
                return s === t ? o ? n in o ? o[n] : o.document.documentElement[i] : e[i] : (o ? o.scrollTo(r ? b(o).scrollLeft() : s, r ? s : b(o).scrollTop()) : e[i] = s, t)
            }, e, i, arguments.length, null)
        }
    }), b.each({Height: "height", Width: "width"}, function (e, n) {
        b.each({padding: "inner" + e, content: n, "": "outer" + e}, function (r, i) {
            b.fn[i] = function (i, s) {
                var o = arguments.length && (r || "boolean" != typeof i), u = r || (i === !0 || s === !0 ? "margin" : "border");
                return b.access(this, function (n, r, i) {
                    var s;
                    return b.isWindow(n) ? n.document.documentElement["client" + e] : 9 === n.nodeType ? (s = n.documentElement, Math.max(n.body["scroll" + e], s["scroll" + e], n.body["offset" + e], s["offset" + e], s["client" + e])) : i === t ? b.css(n, r, u) : b.style(n, r, i, u)
                }, n, o ? i : t, o, null)
            }
        })
    }), e.jQuery = e.$ = b, "function" == typeof define && define.amd && define.amd.jQuery && define("jquery", [], function () {
        return b
    })
})(window), function (e) {
    e.flexslider = function (t, n) {
        var r = e(t);
        r.vars = e.extend({}, e.flexslider.defaults, n);
        var i = r.vars.namespace, s = window.navigator && window.navigator.msPointerEnabled && window.MSGesture, o = ("ontouchstart"in window || s || window.DocumentTouch && document instanceof DocumentTouch) && r.vars.touch, u = "click touchend MSPointerUp keyup", a = "", f, l = r.vars.direction === "vertical", c = r.vars.reverse, h = r.vars.itemWidth > 0, p = r.vars.animation === "fade", d = r.vars.asNavFor !== "", v = {}, m = !0;
        e.data(t, "flexslider", r), v = {
            init: function () {
                r.animating = !1, r.currentSlide = parseInt(r.vars.startAt ? r.vars.startAt : 0, 10), isNaN(r.currentSlide) && (r.currentSlide = 0), r.animatingTo = r.currentSlide, r.atEnd = r.currentSlide === 0 || r.currentSlide === r.last, r.containerSelector = r.vars.selector.substr(0, r.vars.selector.search(" ")), r.slides = e(r.vars.selector, r), r.container = e(r.containerSelector, r), r.count = r.slides.length, r.syncExists = e(r.vars.sync).length > 0, r.vars.animation === "slide" && (r.vars.animation = "swing"), r.prop = l ? "top" : "marginLeft", r.args = {}, r.manualPause = !1, r.stopped = !1, r.started = !1, r.startTimeout = null, r.transitions = !r.vars.video && !p && r.vars.useCSS && function () {
                        var e = document.createElement("div"), t = ["perspectiveProperty", "WebkitPerspective", "MozPerspective", "OPerspective", "msPerspective"];
                        for (var n in t)if (e.style[t[n]] !== undefined)return r.pfx = t[n].replace("Perspective", "").toLowerCase(), r.prop = "-" + r.pfx + "-transform", !0;
                        return !1
                    }(), r.ensureAnimationEnd = "", r.vars.controlsContainer !== "" && (r.controlsContainer = e(r.vars.controlsContainer).length > 0 && e(r.vars.controlsContainer)), r.vars.manualControls !== "" && (r.manualControls = e(r.vars.manualControls).length > 0 && e(r.vars.manualControls)), r.vars.customDirectionNav !== "" && (r.customDirectionNav = e(r.vars.customDirectionNav).length === 2 && e(r.vars.customDirectionNav)), r.vars.randomize && (r.slides.sort(function () {
                    return Math.round(Math.random()) - .5
                }), r.container.empty().append(r.slides)), r.doMath(), r.setup("init"), r.vars.controlNav && v.controlNav.setup(), r.vars.directionNav && v.directionNav.setup(), r.vars.keyboard && (e(r.containerSelector).length === 1 || r.vars.multipleKeyboard) && e(document).bind("keyup", function (e) {
                    var t = e.keyCode;
                    if (!r.animating && (t === 39 || t === 37)) {
                        var n = t === 39 ? r.getTarget("next") : t === 37 ? r.getTarget("prev") : !1;
                        r.flexAnimate(n, r.vars.pauseOnAction)
                    }
                }), r.vars.mousewheel && r.bind("mousewheel", function (e, t, n, i) {
                    e.preventDefault();
                    var s = t < 0 ? r.getTarget("next") : r.getTarget("prev");
                    r.flexAnimate(s, r.vars.pauseOnAction)
                }), r.vars.pausePlay && v.pausePlay.setup(), r.vars.slideshow && r.vars.pauseInvisible && v.pauseInvisible.init();
                if (r.vars.slideshow) {
                    r.vars.pauseOnHover && r.hover(function () {
                        !r.manualPlay && !r.manualPause && r.pause()
                    }, function () {
                        !r.manualPause && !r.manualPlay && !r.stopped && r.play()
                    });
                    if (!r.vars.pauseInvisible || !v.pauseInvisible.isHidden())r.vars.initDelay > 0 ? r.startTimeout = setTimeout(r.play, r.vars.initDelay) : r.play()
                }
                d && v.asNav.setup(), o && r.vars.touch && v.touch(), (!p || p && r.vars.smoothHeight) && e(window).bind("resize orientationchange focus", v.resize), r.find("img").attr("draggable", "false"), setTimeout(function () {
                    r.vars.start(r)
                }, 200)
            }, asNav: {
                setup: function () {
                    r.asNav = !0, r.animatingTo = Math.floor(r.currentSlide / r.move), r.currentItem = r.currentSlide, r.slides.removeClass(i + "active-slide").eq(r.currentItem).addClass(i + "active-slide"), s ? (t._slider = r, r.slides.each(function () {
                        var t = this;
                        t._gesture = new MSGesture, t._gesture.target = t, t.addEventListener("MSPointerDown", function (e) {
                            e.preventDefault(), e.currentTarget._gesture && e.currentTarget._gesture.addPointer(e.pointerId)
                        }, !1), t.addEventListener("MSGestureTap", function (t) {
                            t.preventDefault();
                            var n = e(this), i = n.index();
                            !e(r.vars.asNavFor).data("flexslider").animating && !n.hasClass("active") && (r.direction = r.currentItem < i ? "next" : "prev", r.flexAnimate(i, r.vars.pauseOnAction, !1, !0, !0))
                        })
                    })) : r.slides.on(u, function (t) {
                        t.preventDefault();
                        var n = e(this), s = n.index(), o = n.offset().left - e(r).scrollLeft();
                        o <= 0 && n.hasClass(i + "active-slide") ? r.flexAnimate(r.getTarget("prev"), !0) : !e(r.vars.asNavFor).data("flexslider").animating && !n.hasClass(i + "active-slide") && (r.direction = r.currentItem < s ? "next" : "prev", r.flexAnimate(s, r.vars.pauseOnAction, !1, !0, !0))
                    })
                }
            }, controlNav: {
                setup: function () {
                    r.manualControls ? v.controlNav.setupManual() : v.controlNav.setupPaging()
                }, setupPaging: function () {
                    var t = r.vars.controlNav === "thumbnails" ? "control-thumbs" : "control-paging", n = 1, s, o;
                    r.controlNavScaffold = e('<ol class="' + i + "control-nav " + i + t + '"></ol>');
                    if (r.pagingCount > 1)for (var f = 0; f < r.pagingCount; f++) {
                        o = r.slides.eq(f), s = r.vars.controlNav === "thumbnails" ? '<img src="' + o.attr("data-thumb") + '"/>' : "<a>" + n + "</a>";
                        if ("thumbnails" === r.vars.controlNav && !0 === r.vars.thumbCaptions) {
                            var l = o.attr("data-thumbcaption");
                            "" !== l && undefined !== l && (s += '<span class="' + i + 'caption">' + l + "</span>")
                        }
                        r.controlNavScaffold.append("<li>" + s + "</li>"), n++
                    }
                    r.controlsContainer ? e(r.controlsContainer).append(r.controlNavScaffold) : r.append(r.controlNavScaffold), v.controlNav.set(), v.controlNav.active(), r.controlNavScaffold.delegate("a, img", u, function (t) {
                        t.preventDefault();
                        if (a === "" || a === t.type) {
                            var n = e(this), s = r.controlNav.index(n);
                            n.hasClass(i + "active") || (r.direction = s > r.currentSlide ? "next" : "prev", r.flexAnimate(s, r.vars.pauseOnAction))
                        }
                        a === "" && (a = t.type), v.setToClearWatchedEvent()
                    })
                }, setupManual: function () {
                    r.controlNav = r.manualControls, v.controlNav.active(), r.controlNav.bind(u, function (t) {
                        t.preventDefault();
                        if (a === "" || a === t.type) {
                            var n = e(this), s = r.controlNav.index(n);
                            n.hasClass(i + "active") || (s > r.currentSlide ? r.direction = "next" : r.direction = "prev", r.flexAnimate(s, r.vars.pauseOnAction))
                        }
                        a === "" && (a = t.type), v.setToClearWatchedEvent()
                    })
                }, set: function () {
                    var t = r.vars.controlNav === "thumbnails" ? "img" : "a";
                    r.controlNav = e("." + i + "control-nav li " + t, r.controlsContainer ? r.controlsContainer : r)
                }, active: function () {
                    r.controlNav.removeClass(i + "active").eq(r.animatingTo).addClass(i + "active")
                }, update: function (t, n) {
                    r.pagingCount > 1 && t === "add" ? r.controlNavScaffold.append(e("<li><a>" + r.count + "</a></li>")) : r.pagingCount === 1 ? r.controlNavScaffold.find("li").remove() : r.controlNav.eq(n).closest("li").remove(), v.controlNav.set(), r.pagingCount > 1 && r.pagingCount !== r.controlNav.length ? r.update(n, t) : v.controlNav.active()
                }
            }, directionNav: {
                setup: function () {
                    var t = e('<ul class="' + i + 'direction-nav"><li class="' + i + 'nav-prev"><a class="' + i + 'prev" href="#">' + r.vars.prevText + '</a></li><li class="' + i + 'nav-next"><a class="' + i + 'next" href="#">' + r.vars.nextText + "</a></li></ul>");
                    r.customDirectionNav ? r.directionNav = r.customDirectionNav : r.controlsContainer ? (e(r.controlsContainer).append(t), r.directionNav = e("." + i + "direction-nav li a", r.controlsContainer)) : (r.append(t), r.directionNav = e("." + i + "direction-nav li a", r)), v.directionNav.update(), r.directionNav.bind(u, function (t) {
                        t.preventDefault();
                        var n;
                        if (a === "" || a === t.type)n = e(this).hasClass(i + "next") ? r.getTarget("next") : r.getTarget("prev"), r.flexAnimate(n, r.vars.pauseOnAction);
                        a === "" && (a = t.type), v.setToClearWatchedEvent()
                    })
                }, update: function () {
                    var e = i + "disabled";
                    r.pagingCount === 1 ? r.directionNav.addClass(e).attr("tabindex", "-1") : r.vars.animationLoop ? r.directionNav.removeClass(e).removeAttr("tabindex") : r.animatingTo === 0 ? r.directionNav.removeClass(e).filter("." + i + "prev").addClass(e).attr("tabindex", "-1") : r.animatingTo === r.last ? r.directionNav.removeClass(e).filter("." + i + "next").addClass(e).attr("tabindex", "-1") : r.directionNav.removeClass(e).removeAttr("tabindex")
                }
            }, pausePlay: {
                setup: function () {
                    var t = e('<div class="' + i + 'pauseplay"><a></a></div>');
                    r.controlsContainer ? (r.controlsContainer.append(t), r.pausePlay = e("." + i + "pauseplay a", r.controlsContainer)) : (r.append(t), r.pausePlay = e("." + i + "pauseplay a", r)), v.pausePlay.update(r.vars.slideshow ? i + "pause" : i + "play"), r.pausePlay.bind(u, function (t) {
                        t.preventDefault();
                        if (a === "" || a === t.type)e(this).hasClass(i + "pause") ? (r.manualPause = !0, r.manualPlay = !1, r.pause()) : (r.manualPause = !1, r.manualPlay = !0, r.play());
                        a === "" && (a = t.type), v.setToClearWatchedEvent()
                    })
                }, update: function (e) {
                    e === "play" ? r.pausePlay.removeClass(i + "pause").addClass(i + "play").html(r.vars.playText) : r.pausePlay.removeClass(i + "play").addClass(i + "pause").html(r.vars.pauseText)
                }
            }, touch: function () {
                var e, n, i, o, u, a, f, d, v, m = !1, g = 0, y = 0, b = 0;
                if (!s)f = function (s) {
                    if (r.animating)s.preventDefault(); else if (window.navigator.msPointerEnabled || s.touches.length === 1)r.pause(), o = l ? r.h : r.w, a = Number(new Date), g = s.touches[0].pageX, y = s.touches[0].pageY, i = h && c && r.animatingTo === r.last ? 0 : h && c ? r.limit - (r.itemW + r.vars.itemMargin) * r.move * r.animatingTo : h && r.currentSlide === r.last ? r.limit : h ? (r.itemW + r.vars.itemMargin) * r.move * r.currentSlide : c ? (r.last - r.currentSlide + r.cloneOffset) * o : (r.currentSlide + r.cloneOffset) * o, e = l ? y : g, n = l ? g : y, t.addEventListener("touchmove", d, !1), t.addEventListener("touchend", v, !1)
                }, d = function (t) {
                    g = t.touches[0].pageX, y = t.touches[0].pageY, u = l ? e - y : e - g, m = l ? Math.abs(u) < Math.abs(g - n) : Math.abs(u) < Math.abs(y - n);
                    var s = 500;
                    if (!m || Number(new Date) - a > s)t.preventDefault(), !p && r.transitions && (r.vars.animationLoop || (u /= r.currentSlide === 0 && u < 0 || r.currentSlide === r.last && u > 0 ? Math.abs(u) / o + 2 : 1), r.setProps(i + u, "setTouch"))
                }, v = function (s) {
                    t.removeEventListener("touchmove", d, !1);
                    if (r.animatingTo === r.currentSlide && !m && u !== null) {
                        var f = c ? -u : u, l = f > 0 ? r.getTarget("next") : r.getTarget("prev");
                        r.canAdvance(l) && (Number(new Date) - a < 550 && Math.abs(f) > 50 || Math.abs(f) > o / 2) ? r.flexAnimate(l, r.vars.pauseOnAction) : p || r.flexAnimate(r.currentSlide, r.vars.pauseOnAction, !0)
                    }
                    t.removeEventListener("touchend", v, !1), e = null, n = null, u = null, i = null
                }, t.addEventListener("touchstart", f, !1); else {
                    t.style.msTouchAction = "none", t._gesture = new MSGesture, t._gesture.target = t, t.addEventListener("MSPointerDown", w, !1), t._slider = r, t.addEventListener("MSGestureChange", E, !1), t.addEventListener("MSGestureEnd", S, !1);
                    function w(e) {
                        e.stopPropagation(), r.animating ? e.preventDefault() : (r.pause(), t._gesture.addPointer(e.pointerId), b = 0, o = l ? r.h : r.w, a = Number(new Date), i = h && c && r.animatingTo === r.last ? 0 : h && c ? r.limit - (r.itemW + r.vars.itemMargin) * r.move * r.animatingTo : h && r.currentSlide === r.last ? r.limit : h ? (r.itemW + r.vars.itemMargin) * r.move * r.currentSlide : c ? (r.last - r.currentSlide + r.cloneOffset) * o : (r.currentSlide + r.cloneOffset) * o)
                    }

                    function E(e) {
                        e.stopPropagation();
                        var n = e.target._slider;
                        if (!n)return;
                        var r = -e.translationX, s = -e.translationY;
                        b += l ? s : r, u = b, m = l ? Math.abs(b) < Math.abs(-r) : Math.abs(b) < Math.abs(-s);
                        if (e.detail === e.MSGESTURE_FLAG_INERTIA) {
                            setImmediate(function () {
                                t._gesture.stop()
                            });
                            return
                        }
                        if (!m || Number(new Date) - a > 500)e.preventDefault(), !p && n.transitions && (n.vars.animationLoop || (u = b / (n.currentSlide === 0 && b < 0 || n.currentSlide === n.last && b > 0 ? Math.abs(b) / o + 2 : 1)), n.setProps(i + u, "setTouch"))
                    }

                    function S(t) {
                        t.stopPropagation();
                        var r = t.target._slider;
                        if (!r)return;
                        if (r.animatingTo === r.currentSlide && !m && u !== null) {
                            var s = c ? -u : u, f = s > 0 ? r.getTarget("next") : r.getTarget("prev");
                            r.canAdvance(f) && (Number(new Date) - a < 550 && Math.abs(s) > 50 || Math.abs(s) > o / 2) ? r.flexAnimate(f, r.vars.pauseOnAction) : p || r.flexAnimate(r.currentSlide, r.vars.pauseOnAction, !0)
                        }
                        e = null, n = null, u = null, i = null, b = 0
                    }
                }
            }, resize: function () {
                !r.animating && r.is(":visible") && (h || r.doMath(), p ? v.smoothHeight() : h ? (r.slides.width(r.computedW), r.update(r.pagingCount), r.setProps()) : l ? (r.viewport.height(r.h), r.setProps(r.h, "setTotal")) : (r.vars.smoothHeight && v.smoothHeight(), r.newSlides.width(r.computedW), r.setProps(r.computedW, "setTotal")))
            }, smoothHeight: function (e) {
                if (!l || p) {
                    var t = p ? r : r.viewport;
                    e ? t.animate({height: r.slides.eq(r.animatingTo).height()}, e) : t.height(r.slides.eq(r.animatingTo).height())
                }
            }, sync: function (t) {
                var n = e(r.vars.sync).data("flexslider"), i = r.animatingTo;
                switch (t) {
                    case"animate":
                        n.flexAnimate(i, r.vars.pauseOnAction, !1, !0);
                        break;
                    case"play":
                        !n.playing && !n.asNav && n.play();
                        break;
                    case"pause":
                        n.pause()
                }
            }, uniqueID: function (t) {
                return t.filter("[id]").add(t.find("[id]")).each(function () {
                    var t = e(this);
                    t.attr("id", t.attr("id") + "_clone")
                }), t
            }, pauseInvisible: {
                visProp: null, init: function () {
                    var e = v.pauseInvisible.getHiddenProp();
                    if (e) {
                        var t = e.replace(/[H|h]idden/, "") + "visibilitychange";
                        document.addEventListener(t, function () {
                            v.pauseInvisible.isHidden() ? r.startTimeout ? clearTimeout(r.startTimeout) : r.pause() : r.started ? r.play() : r.vars.initDelay > 0 ? setTimeout(r.play, r.vars.initDelay) : r.play()
                        })
                    }
                }, isHidden: function () {
                    var e = v.pauseInvisible.getHiddenProp();
                    return e ? document[e] : !1
                }, getHiddenProp: function () {
                    var e = ["webkit", "moz", "ms", "o"];
                    if ("hidden"in document)return "hidden";
                    for (var t = 0; t < e.length; t++)if (e[t] + "Hidden"in document)return e[t] + "Hidden";
                    return null
                }
            }, setToClearWatchedEvent: function () {
                clearTimeout(f), f = setTimeout(function () {
                    a = ""
                }, 3e3)
            }
        }, r.flexAnimate = function (t, n, s, u, a) {
            !r.vars.animationLoop && t !== r.currentSlide && (r.direction = t > r.currentSlide ? "next" : "prev"), d && r.pagingCount === 1 && (r.direction = r.currentItem < t ? "next" : "prev");
            if (!r.animating && (r.canAdvance(t, a) || s) && r.is(":visible")) {
                if (d && u) {
                    var f = e(r.vars.asNavFor).data("flexslider");
                    r.atEnd = t === 0 || t === r.count - 1, f.flexAnimate(t, !0, !1, !0, a), r.direction = r.currentItem < t ? "next" : "prev", f.direction = r.direction;
                    if (Math.ceil((t + 1) / r.visible) - 1 === r.currentSlide || t === 0)return r.currentItem = t, r.slides.removeClass(i + "active-slide").eq(t).addClass(i + "active-slide"), !1;
                    r.currentItem = t, r.slides.removeClass(i + "active-slide").eq(t).addClass(i + "active-slide"), t = Math.floor(t / r.visible)
                }
                r.animating = !0, r.animatingTo = t, n && r.pause(), r.vars.before(r), r.syncExists && !a && v.sync("animate"), r.vars.controlNav && v.controlNav.active(), h || r.slides.removeClass(i + "active-slide").eq(t).addClass(i + "active-slide"), r.atEnd = t === 0 || t === r.last, r.vars.directionNav && v.directionNav.update(), t === r.last && (r.vars.end(r), r.vars.animationLoop || r.pause());
                if (!p) {
                    var m = l ? r.slides.filter(":first").height() : r.computedW, g, y, b;
                    h ? (g = r.vars.itemMargin, b = (r.itemW + g) * r.move * r.animatingTo, y = b > r.limit && r.visible !== 1 ? r.limit : b) : r.currentSlide === 0 && t === r.count - 1 && r.vars.animationLoop && r.direction !== "next" ? y = c ? (r.count + r.cloneOffset) * m : 0 : r.currentSlide === r.last && t === 0 && r.vars.animationLoop && r.direction !== "prev" ? y = c ? 0 : (r.count + 1) * m : y = c ? (r.count - 1 - t + r.cloneOffset) * m : (t + r.cloneOffset) * m, r.setProps(y, "", r.vars.animationSpeed);
                    if (r.transitions) {
                        if (!r.vars.animationLoop || !r.atEnd)r.animating = !1, r.currentSlide = r.animatingTo;
                        r.container.unbind("webkitTransitionEnd transitionend"), r.container.bind("webkitTransitionEnd transitionend", function () {
                            clearTimeout(r.ensureAnimationEnd), r.wrapup(m)
                        }), clearTimeout(r.ensureAnimationEnd), r.ensureAnimationEnd = setTimeout(function () {
                            r.wrapup(m)
                        }, r.vars.animationSpeed + 100)
                    } else r.container.animate(r.args, r.vars.animationSpeed, r.vars.easing, function () {
                        r.wrapup(m)
                    })
                } else o ? (r.slides.eq(r.currentSlide).css({opacity: 0, zIndex: 1}), r.slides.eq(t).css({
                    opacity: 1,
                    zIndex: 2
                }), r.wrapup(m)) : (r.slides.eq(r.currentSlide).css({zIndex: 1}).animate({opacity: 0}, r.vars.animationSpeed, r.vars.easing), r.slides.eq(t).css({zIndex: 2}).animate({opacity: 1}, r.vars.animationSpeed, r.vars.easing, r.wrapup));
                r.vars.smoothHeight && v.smoothHeight(r.vars.animationSpeed)
            }
        }, r.wrapup = function (e) {
            !p && !h && (r.currentSlide === 0 && r.animatingTo === r.last && r.vars.animationLoop ? r.setProps(e, "jumpEnd") : r.currentSlide === r.last && r.animatingTo === 0 && r.vars.animationLoop && r.setProps(e, "jumpStart")), r.animating = !1, r.currentSlide = r.animatingTo, r.vars.after(r)
        }, r.animateSlides = function () {
            !r.animating && m && r.flexAnimate(r.getTarget("next"))
        }, r.pause = function () {
            clearInterval(r.animatedSlides), r.animatedSlides = null, r.playing = !1, r.vars.pausePlay && v.pausePlay.update("play"), r.syncExists && v.sync("pause")
        }, r.play = function () {
            r.playing && clearInterval(r.animatedSlides), r.animatedSlides = r.animatedSlides || setInterval(r.animateSlides, r.vars.slideshowSpeed), r.started = r.playing = !0, r.vars.pausePlay && v.pausePlay.update("pause"), r.syncExists && v.sync("play")
        }, r.stop = function () {
            r.pause(), r.stopped = !0
        }, r.canAdvance = function (e, t) {
            var n = d ? r.pagingCount - 1 : r.last;
            return t ? !0 : d && r.currentItem === r.count - 1 && e === 0 && r.direction === "prev" ? !0 : d && r.currentItem === 0 && e === r.pagingCount - 1 && r.direction !== "next" ? !1 : e === r.currentSlide && !d ? !1 : r.vars.animationLoop ? !0 : r.atEnd && r.currentSlide === 0 && e === n && r.direction !== "next" ? !1 : r.atEnd && r.currentSlide === n && e === 0 && r.direction === "next" ? !1 : !0
        }, r.getTarget = function (e) {
            return r.direction = e, e === "next" ? r.currentSlide === r.last ? 0 : r.currentSlide + 1 : r.currentSlide === 0 ? r.last : r.currentSlide - 1
        }, r.setProps = function (e, t, n) {
            var i = function () {
                var n = e ? e : (r.itemW + r.vars.itemMargin) * r.move * r.animatingTo, i = function () {
                    if (h)return t === "setTouch" ? e : c && r.animatingTo === r.last ? 0 : c ? r.limit - (r.itemW + r.vars.itemMargin) * r.move * r.animatingTo : r.animatingTo === r.last ? r.limit : n;
                    switch (t) {
                        case"setTotal":
                            return c ? (r.count - 1 - r.currentSlide + r.cloneOffset) * e : (r.currentSlide + r.cloneOffset) * e;
                        case"setTouch":
                            return c ? e : e;
                        case"jumpEnd":
                            return c ? e : r.count * e;
                        case"jumpStart":
                            return c ? r.count * e : e;
                        default:
                            return e
                    }
                }();
                return i * -1 + "px"
            }();
            r.transitions && (i = l ? "translate3d(0," + i + ",0)" : "translate3d(" + i + ",0,0)", n = n !== undefined ? n / 1e3 + "s" : "0s", r.container.css("-" + r.pfx + "-transition-duration", n), r.container.css("transition-duration", n)), r.args[r.prop] = i, (r.transitions || n === undefined) && r.container.css(r.args), r.container.css("transform", i)
        }, r.setup = function (t) {
            if (!p) {
                var n, s;
                t === "init" && (r.viewport = e('<div class="' + i + 'viewport"></div>').css({
                    overflow: "hidden",
                    position: "relative"
                }).appendTo(r).append(r.container), r.cloneCount = 0, r.cloneOffset = 0, c && (s = e.makeArray(r.slides).reverse(), r.slides = e(s), r.container.empty().append(r.slides))), r.vars.animationLoop && !h && (r.cloneCount = 2, r.cloneOffset = 1, t !== "init" && r.container.find(".clone").remove(), r.container.append(v.uniqueID(r.slides.first().clone().addClass("clone")).attr("aria-hidden", "true")).prepend(v.uniqueID(r.slides.last().clone().addClass("clone")).attr("aria-hidden", "true"))), r.newSlides = e(r.vars.selector, r), n = c ? r.count - 1 - r.currentSlide + r.cloneOffset : r.currentSlide + r.cloneOffset, l && !h ? (r.container.height((r.count + r.cloneCount) * 200 + "%").css("position", "absolute").width("100%"), setTimeout(function () {
                    r.newSlides.css({display: "block"}), r.doMath(), r.viewport.height(r.h), r.setProps(n * r.h, "init")
                }, t === "init" ? 100 : 0)) : (r.container.width((r.count + r.cloneCount) * 200 + "%"), r.setProps(n * r.computedW, "init"), setTimeout(function () {
                    r.doMath(), r.newSlides.css({
                        width: r.computedW,
                        "float": "left",
                        display: "block"
                    }), r.vars.smoothHeight && v.smoothHeight()
                }, t === "init" ? 100 : 0))
            } else r.slides.css({
                width: "100%",
                "float": "left",
                marginRight: "-100%",
                position: "relative"
            }), t === "init" && (o ? r.slides.css({
                opacity: 0,
                display: "block",
                webkitTransition: "opacity " + r.vars.animationSpeed / 1e3 + "s ease",
                zIndex: 1
            }).eq(r.currentSlide).css({opacity: 1, zIndex: 2}) : r.vars.fadeFirstSlide == 0 ? r.slides.css({
                opacity: 0,
                display: "block",
                zIndex: 1
            }).eq(r.currentSlide).css({zIndex: 2}).css({opacity: 1}) : r.slides.css({
                opacity: 0,
                display: "block",
                zIndex: 1
            }).eq(r.currentSlide).css({zIndex: 2}).animate({opacity: 1}, r.vars.animationSpeed, r.vars.easing)), r.vars.smoothHeight && v.smoothHeight();
            h || r.slides.removeClass(i + "active-slide").eq(r.currentSlide).addClass(i + "active-slide"), r.vars.init(r)
        }, r.doMath = function () {
            var e = r.slides.first(), t = r.vars.itemMargin, n = r.vars.minItems, i = r.vars.maxItems;
            r.w = r.viewport === undefined ? r.width() : r.viewport.width(), r.h = e.height(), r.boxPadding = e.outerWidth() - e.width(), h ? (r.itemT = r.vars.itemWidth + t, r.minW = n ? n * r.itemT : r.w, r.maxW = i ? i * r.itemT - t : r.w, r.itemW = r.minW > r.w ? (r.w - t * (n - 1)) / n : r.maxW < r.w ? (r.w - t * (i - 1)) / i : r.vars.itemWidth > r.w ? r.w : r.vars.itemWidth, r.visible = Math.floor(r.w / r.itemW), r.move = r.vars.move > 0 && r.vars.move < r.visible ? r.vars.move : r.visible, r.pagingCount = Math.ceil((r.count - r.visible) / r.move + 1), r.last = r.pagingCount - 1, r.limit = r.pagingCount === 1 ? 0 : r.vars.itemWidth > r.w ? r.itemW * (r.count - 1) + t * (r.count - 1) : (r.itemW + t) * r.count - r.w - t) : (r.itemW = r.w, r.pagingCount = r.count, r.last = r.count - 1), r.computedW = r.itemW - r.boxPadding
        }, r.update = function (e, t) {
            r.doMath(), h || (e < r.currentSlide ? r.currentSlide += 1 : e <= r.currentSlide && e !== 0 && (r.currentSlide -= 1), r.animatingTo = r.currentSlide);
            if (r.vars.controlNav && !r.manualControls)if (t === "add" && !h || r.pagingCount > r.controlNav.length)v.controlNav.update("add"); else if (t === "remove" && !h || r.pagingCount < r.controlNav.length)h && r.currentSlide > r.last && (r.currentSlide -= 1, r.animatingTo -= 1), v.controlNav.update("remove", r.last);
            r.vars.directionNav && v.directionNav.update()
        }, r.addSlide = function (t, n) {
            var i = e(t);
            r.count += 1, r.last = r.count - 1, l && c ? n !== undefined ? r.slides.eq(r.count - n).after(i) : r.container.prepend(i) : n !== undefined ? r.slides.eq(n).before(i) : r.container.append(i), r.update(n, "add"), r.slides = e(r.vars.selector + ":not(.clone)", r), r.setup(), r.vars.added(r)
        }, r.removeSlide = function (t) {
            var n = isNaN(t) ? r.slides.index(e(t)) : t;
            r.count -= 1, r.last = r.count - 1, isNaN(t) ? e(t, r.slides).remove() : l && c ? r.slides.eq(r.last).remove() : r.slides.eq(t).remove(), r.doMath(), r.update(n, "remove"), r.slides = e(r.vars.selector + ":not(.clone)", r), r.setup(), r.vars.removed(r)
        }, v.init()
    }, e(window).blur(function (e) {
        focused = !1
    }).focus(function (e) {
        focused = !0
    }), e.flexslider.defaults = {
        namespace: "flex-",
        selector: ".slides > li",
        animation: "fade",
        easing: "swing",
        direction: "horizontal",
        reverse: !1,
        animationLoop: !0,
        smoothHeight: !1,
        startAt: 0,
        slideshow: !0,
        slideshowSpeed: 7e3,
        animationSpeed: 600,
        initDelay: 0,
        randomize: !1,
        fadeFirstSlide: !0,
        thumbCaptions: !1,
        pauseOnAction: !0,
        pauseOnHover: !1,
        pauseInvisible: !0,
        useCSS: !0,
        touch: !0,
        video: !1,
        controlNav: !0,
        directionNav: !0,
        prevText: "Previous",
        nextText: "Next",
        keyboard: !0,
        multipleKeyboard: !1,
        mousewheel: !1,
        pausePlay: !1,
        pauseText: "Pause",
        playText: "Play",
        controlsContainer: "",
        manualControls: "",
        customDirectionNav: "",
        sync: "",
        asNavFor: "",
        itemWidth: 0,
        itemMargin: 0,
        minItems: 1,
        maxItems: 0,
        move: 0,
        allowOneSlide: !0,
        start: function () {
        },
        before: function () {
        },
        after: function () {
        },
        end: function () {
        },
        added: function () {
        },
        removed: function () {
        },
        init: function () {
        }
    }, e.fn.flexslider = function (t) {
        t === undefined && (t = {});
        if (typeof t == "object")return this.each(function () {
            var n = e(this), r = t.selector ? t.selector : ".slides > li", i = n.find(r);
            i.length === 1 && t.allowOneSlide === !0 || i.length === 0 ? (i.fadeIn(400), t.start && t.start(n)) : n.data("flexslider") === undefined && new e.flexslider(this, t)
        });
        var n = e(this).data("flexslider");
        switch (t) {
            case"play":
                n.play();
                break;
            case"pause":
                n.pause();
                break;
            case"stop":
                n.stop();
                break;
            case"next":
                n.flexAnimate(n.getTarget("next"), !0);
                break;
            case"prev":
            case"previous":
                n.flexAnimate(n.getTarget("prev"), !0);
                break;
            default:
                typeof t == "number" && n.flexAnimate(t, !0)
        }
    }
}(jQuery), define("libs/jquery.flexslider", function () {
}), define("data/indexdata", ["jquery"], function (e) {
    var t = {
        getAds: function () {
        }, getGameList: function (t, n, r) {
            e.post(t, n, function (e) {
                r(e)
            }, "json")
        }, getGameGift: function () {
        }
    };
    return t
}), function () {
    "use strict";
    function resolveDefs(e, t, n) {
        return (typeof t == "string" ? t : t.toString()).replace(e.define || skip, function (t, r, i, s) {
            return r.indexOf("def.") === 0 && (r = r.substring(4)), r in n || (i === ":" ? (e.defineParams && s.replace(e.defineParams, function (e, t, i) {
                n[r] = {arg: t, text: i}
            }), r in n || (n[r] = s)) : (new Function("def", "def['" + r + "']=" + s))(n)), ""
        }).replace(e.use || skip, function (t, r) {
            e.useParams && (r = r.replace(e.useParams, function (e, t, r, i) {
                if (n[r] && n[r].arg && i) {
                    var s = (r + ":" + i).replace(/'|\\/g, "_");
                    return n.__exp = n.__exp || {}, n.__exp[s] = n[r].text.replace(new RegExp("(^|[^\\w$])" + n[r].arg + "([^\\w$])", "g"), "$1" + i + "$2"), t + "def.__exp['" + s + "']"
                }
            }));
            var i = (new Function("def", "return " + r))(n);
            return i ? resolveDefs(e, i, n) : i
        })
    }

    function unescape(e) {
        return e.replace(/\\('|\\)/g, "$1").replace(/[\r\t\n]/g, " ")
    }

    var doT = {
        version: "1.0.3",
        templateSettings: {
            evaluate: /\{\{([\s\S]+?(\}?)+)\}\}/g,
            interpolate: /\{\{=([\s\S]+?)\}\}/g,
            encode: /\{\{!([\s\S]+?)\}\}/g,
            use: /\{\{#([\s\S]+?)\}\}/g,
            useParams: /(^|[^\w$])def(?:\.|\[[\'\"])([\w$\.]+)(?:[\'\"]\])?\s*\:\s*([\w$\.]+|\"[^\"]+\"|\'[^\']+\'|\{[^\}]+\})/g,
            define: /\{\{##\s*([\w\.$]+)\s*(\:|=)([\s\S]+?)#\}\}/g,
            defineParams: /^\s*([\w$]+):([\s\S]+)/,
            conditional: /\{\{\?(\?)?\s*([\s\S]*?)\s*\}\}/g,
            iterate: /\{\{~\s*(?:\}\}|([\s\S]+?)\s*\:\s*([\w$]+)\s*(?:\:\s*([\w$]+))?\s*\}\})/g,
            varname: "it",
            strip: !0,
            append: !0,
            selfcontained: !1,
            doNotSkipEncoded: !1
        },
        template: undefined,
        compile: undefined
    }, _globals;
    doT.encodeHTMLSource = function (e) {
        var t = {
            "&": "&#38;",
            "<": "&#60;",
            ">": "&#62;",
            '"': "&#34;",
            "'": "&#39;",
            "/": "&#47;"
        }, n = e ? /[&<>"'\/]/g : /&(?!#?\w+;)|<|>|"|'|\//g;
        return function (e) {
            return e ? e.toString().replace(n, function (e) {
                return t[e] || e
            }) : ""
        }
    }, _globals = function () {
        return this || (0, eval)("this")
    }(), typeof module != "undefined" && module.exports ? module.exports = doT : typeof define == "function" && define.amd ? define("libs/doT", [], function () {
        return doT
    }) : _globals.doT = doT;
    var startend = {
        append: {start: "'+(", end: ")+'", startencode: "'+encodeHTML("},
        split: {start: "';out+=(", end: ");out+='", startencode: "';out+=encodeHTML("}
    }, skip = /$^/;
    doT.template = function (e, t, n) {
        t = t || doT.templateSettings;
        var r = t.append ? startend.append : startend.split, i, s = 0, o, u = t.use || t.define ? resolveDefs(t, e, n || {}) : e;
        u = ("var out='" + (t.strip ? u.replace(/(^|\r|\n)\t* +| +\t*(\r|\n|$)/g, " ").replace(/\r|\n|\t|\/\*[\s\S]*?\*\//g, "") : u).replace(/'|\\/g, "\\$&").replace(t.interpolate || skip, function (e, t) {
            return r.start + unescape(t) + r.end
        }).replace(t.encode || skip, function (e, t) {
            return i = !0, r.startencode + unescape(t) + r.end
        }).replace(t.conditional || skip, function (e, t, n) {
            return t ? n ? "';}else if(" + unescape(n) + "){out+='" : "';}else{out+='" : n ? "';if(" + unescape(n) + "){out+='" : "';}out+='"
        }).replace(t.iterate || skip, function (e, t, n, r) {
            return t ? (s += 1, o = r || "i" + s, t = unescape(t), "';var arr" + s + "=" + t + ";if(arr" + s + "){var " + n + "," + o + "=-1,l" + s + "=arr" + s + ".length-1;while(" + o + "<l" + s + "){" + n + "=arr" + s + "[" + o + "+=1];out+='") : "';} } out+='"
        }).replace(t.evaluate || skip, function (e, t) {
            return "';" + unescape(t) + "out+='"
        }) + "';return out;").replace(/\n/g, "\\n").replace(/\t/g, "\\t").replace(/\r/g, "\\r").replace(/(\s|;|\}|^|\{)out\+='';/g, "$1").replace(/\+''/g, ""), i && (!t.selfcontained && _globals && !_globals._encodeHTML && (_globals._encodeHTML = doT.encodeHTMLSource(t.doNotSkipEncoded)), u = "var encodeHTML = typeof _encodeHTML !== 'undefined' ? _encodeHTML : (" + doT.encodeHTMLSource.toString() + "(" + (t.doNotSkipEncoded || "") + "));" + u);
        try {
            return new Function(t.varname, u)
        } catch (a) {
            throw typeof console != "undefined" && console.log("Could not create a template function: " + u), a
        }
    }, doT.compile = function (e, t) {
        return doT.template(e, null, t)
    }
}(), function (e) {
    typeof define == "function" && define.amd ? define("jquery.cookie", ["jquery"], e) : typeof exports == "object" ? module.exports = e(require("jquery")) : e(jQuery)
}(function (e) {
    function n(e) {
        return u.raw ? e : encodeURIComponent(e)
    }

    function r(e) {
        return u.raw ? e : decodeURIComponent(e)
    }

    function i(e) {
        return n(u.json ? JSON.stringify(e) : String(e))
    }

    function s(e) {
        e.indexOf('"') === 0 && (e = e.slice(1, -1).replace(/\\"/g, '"').replace(/\\\\/g, "\\"));
        try {
            return e = decodeURIComponent(e.replace(t, " ")), u.json ? JSON.parse(e) : e
        } catch (n) {
        }
    }

    function o(t, n) {
        var r = u.raw ? t : s(t);
        return e.isFunction(n) ? n(r) : r
    }

    var t = /\+/g, u = e.cookie = function (t, s, a) {
        if (arguments.length > 1 && !e.isFunction(s)) {
            a = e.extend({}, u.defaults, a);
            if (typeof a.expires == "number") {
                var f = a.expires, l = a.expires = new Date;
                l.setMilliseconds(l.getMilliseconds() + f * 864e5)
            }
            return document.cookie = [n(t), "=", i(s), a.expires ? "; expires=" + a.expires.toUTCString() : "", a.path ? "; path=" + a.path : "", a.domain ? "; domain=" + a.domain : "", a.secure ? "; secure" : ""].join("")
        }
        var c = t ? undefined : {}, h = document.cookie ? document.cookie.split("; ") : [], p = 0, d = h.length;
        for (; p < d; p++) {
            var v = h[p].split("="), m = r(v.shift()), g = v.join("=");
            if (t === m) {
                c = o(g, s);
                break
            }
            !t && (g = o(g)) !== undefined && (c[m] = g)
        }
        return c
    };
    u.defaults = {}, e.removeCookie = function (t, n) {
        return e.cookie(t, "", e.extend({}, n, {expires: -1})), !e.cookie(t)
    }
}), define("common/eventbase", ["jquery", "libs/doT", "jquery.cookie"], function (e, t) {
    function r(t, n) {
        var r = t.length, i = n.length, s = {}, o = 0;
        if (r >= i && i > 0)o = i; else if (r < i && r > 0)o = r; else if (r == 0 || i == 0)return;
        for (var u = 0; u < o; u++)s[t[u]] = n[u];
        e.extend(s)
    }

    function i(t, n) {
        var r = {};
        r[t] = n, e.extend(r)
    }

    function s(t) {
        e.extend(t)
    }

    function o(t) {
        var n = t[0], r = t.length - 1;
        switch (r) {
            case 0:
                e[n]();
                break;
            case 1:
                e[n](t[1]);
                break;
            case 2:
                e[n](t[1], t[2]);
                break;
            case 3:
                e[n](t[1], t[2], t[3]);
                break;
            case 4:
                e[n](t[1], t[2], t[3], t[4]);
                break;
            case 5:
                e[n](t[1], t[2], t[3], t[4], t[5])
        }
    }

    function u(e, t) {
        var n = {
            "M+": e.getMonth() + 1,
            "d+": e.getDate(),
            "h+": e.getHours(),
            "m+": e.getMinutes(),
            "s+": e.getSeconds(),
            "q+": Math.floor((e.getMonth() + 3) / 3),
            S: e.getMilliseconds()
        };
        /(y+)/.test(t) && (t = t.replace(RegExp.$1, (e.getFullYear() + "").substr(4 - RegExp.$1.length)));
        for (var r in n)(new RegExp("(" + r + ")")).test(t) && (t = t.replace(RegExp.$1, RegExp.$1.length == 1 ? n[r] : ("00" + n[r]).substr(("" + n[r]).length)));
        return t
    }

    var n = {
        userInfoTemp: "", staticTemp: "", on: function (t, n) {
            var o = typeof t, u = typeof n;
            o === "string" && u === "function" ? i(t, n) : e.isArray(t) && e.isArray(n) ? r(t, n) : arguments.length == 1 && typeof t == "object" && s(t)
        }, emmit: function (t, n) {
            if (typeof e.eventName == "undefined" && typeof e[t] == "undefined")return;
            o(arguments)
        }, loadTem: function (t) {
            var r = '<div id="dot-template" style="display:none;"></div>', i, s;
            return e.ajax({
                type: "get", datatype: "html", url: t, async: !1, success: function (t) {
                    r = e(r).append(t), e(document.body).append(r), i = e("#dot-template"), n.userInfoTemp = i, e("#dot-template").remove()
                }
            }), i
        }, replaceTem: function (e) {
            return e = e.replace(/\&lt;/g, "<").replace(/\&gt;/g, ">").replace(/\&amp;\&amp;/g, "&&"), e
        }, compileTem: function (e, n) {
            var r = t.template(e), i = r(n);
            return i
        }, dateFormat: function (e, t) {
            return typeof t == "undefined" && (t = "yyyy-MM-dd hh:mm:ss"), u(new Date(e), t)
        }, getNowDate: function (e) {
            return typeof e == "undefined" && (e = "yyyy-MM-dd hh:mm:ss"), u(new Date, e)
        }, getUrlParameter: function (e, t) {
            var n = arguments.length;
            n == 1 && (t = e, e = window.location.href);
            var r = new RegExp("(^|&)" + t + "=([^&]*)(&|$)"), i = e.substr(e.indexOf("?")).substr(1).match(r);
            return i != null ? decodeURIComponent(i[2]) : ""
        }, getNormalImg: function (e) {
            var t = e.length, n;
            for (var r = 0; r < t; r++)n = e[r].indexOf("?"), n >= 0 && (e[r] = e[r].substring(0, n));
            return e
        }, getCookie: function (e) {
            if (document.cookie.length > 0) {
                c_start = document.cookie.indexOf(e + "=");
                if (c_start != -1)return c_start = c_start + e.length + 1, c_end = document.cookie.indexOf(";", c_start), c_end == -1 && (c_end = document.cookie.length), JSON.parse(unescape(document.cookie.substring(c_start, c_end)))
            }
            return null
        }, deleteCookie: function () {
        }, logout: function () {
            e.removeCookie("wy_self_info", {path: "/"}), e.removeCookie("wy_user", {path: "/"}), window.location.href = "http://wx.1758.com/game/platform/v1.0/user/flogin?appKey=ba0ab54c1eb63a776fa477153a0a354b"
        }, isLogin: function () {
            var e = document.cookie, t = e.indexOf("wy_user");
            if (t >= 0)return !0;
            window.location.href = "http://wx.1758.com/game/platform/v1.0/user/flogin?appKey=ba0ab54c1eb63a776fa477153a0a354b"
        }, userTerminal: function () {
            var e = window.navigator.userAgent.toLowerCase();
            if (e.match(/MicroMessenger/i) == "micromessenger" && e.match(/dwjia/i) != "dwjia")return "weixin";
            if (e.match(/dwjia/i) != "dwjia") {
                var t = this.getUrlParameter("fork");
                return t == 4 ? "androidclient" : t == 5 ? "iphoneclient" : "others"
            }
            if (e.match(/iPhone/i) == "iphone")return "iphoneclient";
            if (e.match(/Android/i) == "android")return "androidclient"
        }, tip: function (t) {
            var n = {title: "信息提示", content: ""}, t = e.extend(!0, n, t), r = "";
            r = '<div class="tip"><div class="tip-dialog"><div class="tip-wrapper"><div class="tip-content"><div class="tip-header"><button type="button" class="tip-close"><span>×</span></button><h4 class="tip-title">' + t.title + "</h4>" + "</div>" + '<div class="tip-body">' + t.content + "</div>" + "</div>" + "</div>" + "</div>" + "</div>", e("body").append(r), e(document).on("click", ".tip,.tip-close", function (t) {
                t = event || window.event;
                var n = e(t.target);
                if (n.parents(".tip-close").length > 0)n.parents(".tip").remove(); else {
                    if (n.parents(".tip-content").length > 0)return;
                    n.parents(".tip").remove()
                }
            })
        }, isAddHeader: function () {
            var t = this.userTerminal(), n = this.staticTemp;
            if (t == "others" || t == "weixin") {
                n || (this.staticTemp = this.loadTem("page/staticTem.htm"), n = this.staticTemp);
                var r = n.find("#head");
                e("body").prepend(r)
            }
        }, isAddHeaderIndex: function () {
            var t = this.userTerminal(), n = this.staticTemp;
            if (t == "others" || t == "weixin") {
                n || (this.staticTemp = this.loadTem("page/staticTem.htm"), n = this.staticTemp);
                var r = n.find("#headContent");
                e("body").prepend(r)
            }
        }, addHeaderNohome: function () {
            var t = this.userTerminal(), n = this.staticTemp;
            if (t == "others" || t == "weixin") {
                n || (this.staticTemp = this.loadTem("page/staticHeaderTem.htm"), n = this.staticTemp);
                var r = n.find("#head");
                e("body").prepend(r)
            }
        }, isAddFooter: function (t) {
            var n = this.userTerminal(), r = this.staticTemp, i;
            t || (t = "game");
            if (n == "others" || n == "weixin") {
                r || (this.staticTemp = this.loadTem("page/staticTem.htm"), r = this.staticTemp);
                switch (t) {
                    case"game":
                        i = r.find("#base-footer-game");
                        break;
                    case"newsfeed":
                        i = r.find("#base-footer-newsfeed");
                        break;
                    case"user":
                        this.getUrlParameter("sid") || (i = r.find("#base-footer-user"))
                }
                !i || (e("body").addClass("y-tab"), e("body").append(i))
            }
        }, isAddHeadFooter: function (e) {
            this.isAddHeader(), this.isAddFooter(e)
        }, yjuafixed: function (t) {
            var n = e(t).offset().top, r = function () {
                var r = e(window).scrollTop();
                r > n ? e(t).css({position: "fixed", top: 0}).addClass("isStuck") : e(t).css({
                    position: "static",
                    top: n
                }).removeClass("isStuck")
            };
            r(), e(window).scroll(function () {
                r()
            })
        }
    };
    return n
}), define("controller/indexcontroller", ["data/indexdata", "common/eventbase"], function (e, t) {
    var n = {};
    return n = {
        getGameList: function (t, n, r) {
            e.getGameList(t, n, function (e) {
                r(e)
            })
        }, getAds: function () {
        }
    }, n
}), function () {
    "use strict";
    function e(t, r) {
        function s(e, t) {
            return function () {
                return e.apply(t, arguments)
            }
        }

        var i;
        r = r || {}, this.trackingClick = !1, this.trackingClickStart = 0, this.targetElement = null, this.touchStartX = 0, this.touchStartY = 0, this.lastTouchIdentifier = 0, this.touchBoundary = r.touchBoundary || 10, this.layer = t, this.tapDelay = r.tapDelay || 200, this.tapTimeout = r.tapTimeout || 700;
        if (e.notNeeded(t))return;
        var o = ["onMouse", "onClick", "onTouchStart", "onTouchMove", "onTouchEnd", "onTouchCancel"], u = this;
        for (var a = 0, f = o.length; a < f; a++)u[o[a]] = s(u[o[a]], u);
        n && (t.addEventListener("mouseover", this.onMouse, !0), t.addEventListener("mousedown", this.onMouse, !0), t.addEventListener("mouseup", this.onMouse, !0)), t.addEventListener("click", this.onClick, !0), t.addEventListener("touchstart", this.onTouchStart, !1), t.addEventListener("touchmove", this.onTouchMove, !1), t.addEventListener("touchend", this.onTouchEnd, !1), t.addEventListener("touchcancel", this.onTouchCancel, !1), Event.prototype.stopImmediatePropagation || (t.removeEventListener = function (e, n, r) {
            var i = Node.prototype.removeEventListener;
            e === "click" ? i.call(t, e, n.hijacked || n, r) : i.call(t, e, n, r)
        }, t.addEventListener = function (e, n, r) {
            var i = Node.prototype.addEventListener;
            e === "click" ? i.call(t, e, n.hijacked || (n.hijacked = function (e) {
                    e.propagationStopped || n(e)
                }), r) : i.call(t, e, n, r)
        }), typeof t.onclick == "function" && (i = t.onclick, t.addEventListener("click", function (e) {
            i(e)
        }, !1), t.onclick = null)
    }

    var t = navigator.userAgent.indexOf("Windows Phone") >= 0, n = navigator.userAgent.indexOf("Android") > 0 && !t, r = /iP(ad|hone|od)/.test(navigator.userAgent) && !t, i = r && /OS 4_\d(_\d)?/.test(navigator.userAgent), s = r && /OS [6-7]_\d/.test(navigator.userAgent), o = navigator.userAgent.indexOf("BB10") > 0;
    e.prototype.needsClick = function (e) {
        switch (e.nodeName.toLowerCase()) {
            case"button":
            case"select":
            case"textarea":
                if (e.disabled)return !0;
                break;
            case"input":
                if (r && e.type === "file" || e.disabled)return !0;
                break;
            case"label":
            case"iframe":
            case"video":
                return !0
        }
        return /\bneedsclick\b/.test(e.className)
    }, e.prototype.needsFocus = function (e) {
        switch (e.nodeName.toLowerCase()) {
            case"textarea":
                return !0;
            case"select":
                return !n;
            case"input":
                switch (e.type) {
                    case"button":
                    case"checkbox":
                    case"file":
                    case"image":
                    case"radio":
                    case"submit":
                        return !1
                }
                return !e.disabled && !e.readOnly;
            default:
                return /\bneedsfocus\b/.test(e.className)
        }
    }, e.prototype.sendClick = function (e, t) {
        var n, r;
        document.activeElement && document.activeElement !== e && document.activeElement.blur(), r = t.changedTouches[0], n = document.createEvent("MouseEvents"), n.initMouseEvent(this.determineEventType(e), !0, !0, window, 1, r.screenX, r.screenY, r.clientX, r.clientY, !1, !1, !1, !1, 0, null), n.forwardedTouchEvent = !0, e.dispatchEvent(n)
    }, e.prototype.determineEventType = function (e) {
        return n && e.tagName.toLowerCase() === "select" ? "mousedown" : "click"
    }, e.prototype.focus = function (e) {
        var t;
        r && e.setSelectionRange && e.type.indexOf("date") !== 0 && e.type !== "time" && e.type !== "month" ? (t = e.value.length, e.setSelectionRange(t, t)) : e.focus()
    }, e.prototype.updateScrollParent = function (e) {
        var t, n;
        t = e.fastClickScrollParent;
        if (!t || !t.contains(e)) {
            n = e;
            do {
                if (n.scrollHeight > n.offsetHeight) {
                    t = n, e.fastClickScrollParent = n;
                    break
                }
                n = n.parentElement
            } while (n)
        }
        t && (t.fastClickLastScrollTop = t.scrollTop)
    }, e.prototype.getTargetElementFromEventTarget = function (e) {
        return e.nodeType === Node.TEXT_NODE ? e.parentNode : e
    }, e.prototype.onTouchStart = function (e) {
        var t, n, s;
        if (e.targetTouches.length > 1)return !0;
        t = this.getTargetElementFromEventTarget(e.target), n = e.targetTouches[0];
        if (r) {
            s = window.getSelection();
            if (s.rangeCount && !s.isCollapsed)return !0;
            if (!i) {
                if (n.identifier && n.identifier === this.lastTouchIdentifier)return e.preventDefault(), !1;
                this.lastTouchIdentifier = n.identifier, this.updateScrollParent(t)
            }
        }
        return this.trackingClick = !0, this.trackingClickStart = e.timeStamp, this.targetElement = t, this.touchStartX = n.pageX, this.touchStartY = n.pageY, e.timeStamp - this.lastClickTime < this.tapDelay && e.preventDefault(), !0
    }, e.prototype.touchHasMoved = function (e) {
        var t = e.changedTouches[0], n = this.touchBoundary;
        return Math.abs(t.pageX - this.touchStartX) > n || Math.abs(t.pageY - this.touchStartY) > n ? !0 : !1
    }, e.prototype.onTouchMove = function (e) {
        if (!this.trackingClick)return !0;
        if (this.targetElement !== this.getTargetElementFromEventTarget(e.target) || this.touchHasMoved(e))this.trackingClick = !1, this.targetElement = null;
        return !0
    }, e.prototype.findControl = function (e) {
        return e.control !== undefined ? e.control : e.htmlFor ? document.getElementById(e.htmlFor) : e.querySelector("button, input:not([type=hidden]), keygen, meter, output, progress, select, textarea")
    }, e.prototype.onTouchEnd = function (e) {
        var t, o, u, a, f, l = this.targetElement;
        if (!this.trackingClick)return !0;
        if (e.timeStamp - this.lastClickTime < this.tapDelay)return this.cancelNextClick = !0, !0;
        if (e.timeStamp - this.trackingClickStart > this.tapTimeout)return !0;
        this.cancelNextClick = !1, this.lastClickTime = e.timeStamp, o = this.trackingClickStart, this.trackingClick = !1, this.trackingClickStart = 0, s && (f = e.changedTouches[0], l = document.elementFromPoint(f.pageX - window.pageXOffset, f.pageY - window.pageYOffset) || l, l.fastClickScrollParent = this.targetElement.fastClickScrollParent), u = l.tagName.toLowerCase();
        if (u === "label") {
            t = this.findControl(l);
            if (t) {
                this.focus(l);
                if (n)return !1;
                l = t
            }
        } else if (this.needsFocus(l)) {
            if (e.timeStamp - o > 100 || r && window.top !== window && u === "input")return this.targetElement = null, !1;
            this.focus(l), this.sendClick(l, e);
            if (!r || u !== "select")this.targetElement = null, e.preventDefault();
            return !1
        }
        if (r && !i) {
            a = l.fastClickScrollParent;
            if (a && a.fastClickLastScrollTop !== a.scrollTop)return !0
        }
        return this.needsClick(l) || (e.preventDefault(), this.sendClick(l, e)), !1
    }, e.prototype.onTouchCancel = function () {
        this.trackingClick = !1, this.targetElement = null
    }, e.prototype.onMouse = function (e) {
        return this.targetElement ? e.forwardedTouchEvent ? !0 : e.cancelable ? !this.needsClick(this.targetElement) || this.cancelNextClick ? (e.stopImmediatePropagation ? e.stopImmediatePropagation() : e.propagationStopped = !0, e.stopPropagation(), e.preventDefault(), !1) : !0 : !0 : !0
    }, e.prototype.onClick = function (e) {
        var t;
        return this.trackingClick ? (this.targetElement = null, this.trackingClick = !1, !0) : e.target.type === "submit" && e.detail === 0 ? !0 : (t = this.onMouse(e), t || (this.targetElement = null), t)
    }, e.prototype.destroy = function () {
        var e = this.layer;
        n && (e.removeEventListener("mouseover", this.onMouse, !0), e.removeEventListener("mousedown", this.onMouse, !0), e.removeEventListener("mouseup", this.onMouse, !0)), e.removeEventListener("click", this.onClick, !0), e.removeEventListener("touchstart", this.onTouchStart, !1), e.removeEventListener("touchmove", this.onTouchMove, !1), e.removeEventListener("touchend", this.onTouchEnd, !1), e.removeEventListener("touchcancel", this.onTouchCancel, !1)
    }, e.notNeeded = function (e) {
        var t, r, i, s;
        if (typeof window.ontouchstart == "undefined")return !0;
        r = +(/Chrome\/([0-9]+)/.exec(navigator.userAgent) || [, 0])[1];
        if (r) {
            if (!n)return !0;
            t = document.querySelector("meta[name=viewport]");
            if (t) {
                if (t.content.indexOf("user-scalable=no") !== -1)return !0;
                if (r > 31 && document.documentElement.scrollWidth <= window.outerWidth)return !0
            }
        }
        if (o) {
            i = navigator.userAgent.match(/Version\/([0-9]*)\.([0-9]*)/);
            if (i[1] >= 10 && i[2] >= 3) {
                t = document.querySelector("meta[name=viewport]");
                if (t) {
                    if (t.content.indexOf("user-scalable=no") !== -1)return !0;
                    if (document.documentElement.scrollWidth <= window.outerWidth)return !0
                }
            }
        }
        if (e.style.msTouchAction === "none" || e.style.touchAction === "manipulation")return !0;
        s = +(/Firefox\/([0-9]+)/.exec(navigator.userAgent) || [, 0])[1];
        if (s >= 27) {
            t = document.querySelector("meta[name=viewport]");
            if (t && (t.content.indexOf("user-scalable=no") !== -1 || document.documentElement.scrollWidth <= window.outerWidth))return !0
        }
        return e.style.touchAction === "none" || e.style.touchAction === "manipulation" ? !0 : !1
    }, e.attach = function (t, n) {
        return new e(t, n)
    }, typeof define == "function" && typeof define.amd == "object" && define.amd ? define("libs/fastclick", [], function () {
        return e
    }) : typeof module != "undefined" && module.exports ? (module.exports = e.attach, module.exports.FastClick = e) : window.FastClick = e
}(), function (e, t) {
    typeof define == "function" && define.amd ? define("libs/echo", [], function () {
        return t(e)
    }) : typeof exports == "object" ? module.exports = t : e.echo = t(e)
}(this, function (e) {
    "use strict";
    var t = {}, n = function () {
    }, r, i, s, o, u, a = function (e) {
        return e.offsetParent === null
    }, f = function (e, t) {
        if (a(e))return !1;
        var n = e.getBoundingClientRect();
        return n.right >= t.l && n.bottom >= t.t && n.left <= t.r && n.top <= t.b
    }, l = function () {
        if (!o && !!i)return;
        clearTimeout(i), i = setTimeout(function () {
            t.render(), i = null
        }, s)
    };
    return t.init = function (i) {
        i = i || {};
        var a = i.offset || 0, f = i.offsetVertical || a, c = i.offsetHorizontal || a, h = function (e, t) {
            return parseInt(e || t, 10)
        };
        r = {
            t: h(i.offsetTop, f),
            b: h(i.offsetBottom, f),
            l: h(i.offsetLeft, c),
            r: h(i.offsetRight, c)
        }, s = h(i.throttle, 250), o = i.debounce !== !1, u = !!i.unload, n = i.callback || n, t.render(), document.addEventListener ? (e.addEventListener("scroll", l, !1), e.addEventListener("load", l, !1)) : (e.attachEvent("onscroll", l), e.attachEvent("onload", l))
    }, t.render = function () {
        var i = document.querySelectorAll("img[data-echo], [data-echo-background]"), s = i.length, o, a, l = {
            l: 0 - r.l,
            t: 0 - r.t,
            b: (e.innerHeight || document.documentElement.clientHeight) + r.b,
            r: (e.innerWidth || document.documentElement.clientWidth) + r.r
        };
        for (var c = 0; c < s; c++)a = i[c], f(a, l) ? (u && a.setAttribute("data-echo-placeholder", a.src), a.getAttribute("data-echo-background") !== null ? a.style.backgroundImage = "url(" + a.getAttribute("data-echo-background") + ")" : a.src = a.getAttribute("data-echo"), u || (a.removeAttribute("data-echo"), a.removeAttribute("data-echo-background")), n(a, "load")) : u && !!(o = a.getAttribute("data-echo-placeholder")) && (a.getAttribute("data-echo-background") !== null ? a.style.backgroundImage = "url(" + o + ")" : a.src = o, a.removeAttribute("data-echo-placeholder"), n(a, "unload"));
        s || t.detach()
    }, t.detach = function () {
        clearTimeout(i)
    }, t
}), require.config({
    baseUrl: "js",
    paths: {
        libs: "libs",
        common: "common",
        data: "data",
        controller: "controller",
        view: "view",
        jquery: "libs/jquery-2.1.4.min",
        doT: "libs/doT",
        database: "data/database",
        "libs/jquery.flexslider": "libs/jquery.flexslider"
    },
    shim: {FastClick: {exports: "FastClick"}, "libs/jquery.flexslider": ["jquery"]}
}), require(["jquery", "libs/jquery.flexslider", "controller/indexcontroller", "common/eventbase", "libs/fastclick", "libs/echo"], function (e, t, n, r, i, s) {
    function l() {
        i.attach(document.body), u = r.loadTem("page/flexslider"), c(), r.isAddHeadFooter("game"), r.yjuafixed(".index-tab")
    }

    function c() {
        var t = location.hash, n = t.length, r = t.substr(1), i;
        n > 0 && (r == "hot" || r == "newgame" || r == "gift" || r == "category") && (o = r);
        switch (o) {
            case"hot":
                i = e("#menu-hot .dk");
                break;
            case"newgame":
                i = e("#menu-newgame .dk");
                break;
            case"gift":
                i = e("#menu-gift .dk");
                break;
            case"category":
                i = e("#menu-category .dk")
        }
        p(i), h(o)
    }

    function h(t) {
        e(".dk").removeClass("m-active"), r.yjuafixed(".index-tab");
        switch (t) {
            case"hot":
                e("#menu-hot .dk").addClass("m-active"), e(".newgame,.gift,.category").addClass("gone"), e(".hot").removeClass("gone");
                break;
            case"newgame":
                e("#menu-newgame .dk").addClass("m-active"), e(".hot,.gift,.category").addClass("gone"), e(".newgame").removeClass("gone");
                break;
            case"gift":
                e("#menu-gift .dk").addClass("m-active"), e(".hot,.newgame,.category").addClass("gone"), e(".gift").removeClass("gone");
                break;
            case"category":
                e("#menu-category .dk").addClass("m-active"), e(".hot,.newgame,.gift").addClass("gone"), e(".category").removeClass("gone");
                break;
            default:
                e("#menu-hot .dk").addClass("m-active"), e(".newgame,.gift,.category").addClass("gone"), e(".hot").removeClass("gone")
        }
    }

    function p(t) {
        var n = t.attr("data-type"), r;
        if (n == "un") {
            switch (o) {
                case"hot":
                    d();
                    break;
                case"newgame":
                    r = e("#newgames .more-info").attr("data-num"), r == "1" && v(r);
                    break;
                case"gift":
                    r = e("#gift-list .more-info").attr("data-num"), r == "1" && m(r);
                    break;
                case"category":
                    g();
                    break;
                default:
                    d()
            }
            t.attr("data-type", "ac")
        }
    }

    function d(e) {
        S(), y(1)
    }

    function v(t) {
        e("#newgames .more-info a").html(f);
        var r = "http://wx.1758.com/game/column/listvremarkugc.html?cid=107";
        infos = {pageNo: t, pageSize: 10, reqType: 1}, n.getGameList(r, infos, N)
    }

    function m(t) {
        e("#gift-list .more-info a").html(f);
        var r = "http://wx.1758.com/game/platform/home/getGiftList", i = {pageNo: t, pageSize: "10"};
        n.getGameList(r, i, C)
    }

    function g() {
        var e = "http://wx.1758.com/game/column/listWxGameCatalogs.html", t = {cid: "110", reqType: "2"};
        n.getGameList(e, t, L)
    }

    function y(t) {
        e("#hot-game .more-info a").html(f);
        var r = "http://wx.1758.com/game/column/listvremarkugc.html?cid=108";
        infos = {pageNo: t, pageSize: 10, reqType: 1}, n.getGameList(r, infos, b)
    }

    function b(t) {
        if (t.length > 0) {
            var n, i, o = e("#hot-game .more-info"), f = parseInt(o.attr("data-num"));
            n = u.find("#newgame").html(), n = r.replaceTem(n), i = r.compileTem(n, t), e("#hot-game .more-info a").html(a), o.attr("data-num", f + 1), o.before(i), s.init()
        } else e("#hot-game .more-info").addClass("gone")
    }

    function w() {
        var e = "http://wx.1758.com/game/column/listvremarkugc.html?cid=121";
        infos = {pageNo: 1, pageSize: 10, reqType: 1}, n.getGameList(e, infos, E)
    }

    function E(t) {
        var n, i;
        n = u.find("#hot-new").html(), n = r.replaceTem(n), i = r.compileTem(n, t), e("#i-new-game").html(i), s.init()
    }

    function S() {
        var e = "http://wx.1758.com/game/platform/home/getTiplist", t = "";
        n.getGameList(e, t, x)
    }

    function x(e) {
        var t, n;
        e.code == 0 && (t = e.tips, n = e.recommendApps, T(t), E(n))
    }

    function T(t) {
        if (t.length > 0) {
            var n, i;
            n = u.find("#slider").html(), n = r.replaceTem(n), i = r.compileTem(n, t), e(".slides").html(i), e(".flexslider").flexslider()
        }
    }

    function N(t) {
        if (t.length > 0) {
            var n, i, o = e("#newgames .more-info"), f = parseInt(o.attr("data-num"));
            n = u.find("#newgame").html(), n = r.replaceTem(n), i = r.compileTem(n, t), e("#newgames .more-info a").html(a), o.attr("data-num", f + 1), o.before(i), s.init()
        } else e("#newgames .more-info").addClass("gone")
    }

    function C(t) {
        if (t.length > 0) {
            var n, i, o = e("#gift-list .more-info"), f = parseInt(o.attr("data-num"));
            n = u.find("#gift").html(), n = r.replaceTem(n), t = k(t), i = r.compileTem(n, t), o.attr("data-num", f + 1), o.before(i), s.init(), e("#gift-list .more-info a").html(a)
        } else e("#gift-list .more-info").addClass("gone")
    }

    function k(e) {
        var t = new Date, n = t.getTime(), r = t.getFullYear(), i = t.getMonth(), s = t.getDate(), o = (new Date(r, i, s, 0, 0, 0)).getTime(), u = o + 864e5, a = u + 864e5, f = a + 864e5, l, c, h, p, d, v;
        for (var m = 0, g = e.length; m < g; m++)l = e[m].gift.beginTime, dd = new Date(l), c = dd.getFullYear(), h = dd.getMonth() + 1 > 9 ? dd.getMonth() + 1 : "0" + (dd.getMonth() + 1), p = dd.getDate() > 9 ? dd.getDate() : "0" + dd.getDate(), d = dd.getHours() > 9 ? dd.getHours() : "0" + dd.getHours(), v = dd.getMinutes() > 9 ? dd.getMinutes() : "0" + dd.getMinutes(), l > n ? l > o && l < u ? e[m].gift.bt = "今日  " + d + ":" + v : l > u && l < a ? e[m].gift.bt = "明日  " + d + ":" + v : l > a && l < f ? e[m].gift.bt = "后天  " + d + ":" + v : e[m].gift.bt = h + "-" + p + " " + d + ":" + v : e[m].gift.bt = h + "-" + p + " " + d + ":" + v;
        return e
    }

    function L(t) {
        var n, i, n = u.find("#category").html();
        i = r.compileTem(n, t), e("#c-list ul").append(i)
    }

    function A(t, n, r) {
        var i, s, o, u;
        i = (new Date).getTime(), s = t - i, u = O(s), u == null ? n.indexOf("今日") >= 0 ? o = "今日后才可领取该礼包" : n.indexOf("明日") >= 0 ? o = "明日后才可领取该礼包" : n.indexOf("后日") >= 0 ? o = "后天才可领取该礼包" : o = n + "领取该礼包" : o = u, e(".ex-con").html(o), e(".ex-info").html("1758客户端玩游戏更流畅、可全屏");
        if (r == "iphoneclient" || r == "androidclient")e(".ex-load").html("知道了"), e(".ex-load").removeAttr("href");
        e(".tip").removeClass("gone")
    }

    function O(e) {
        var t = 864e5, n = 36e5, r = 6e4, i;
        return e > t ? null : e > n ? (i = Math.floor(e / n) + "小时后才可领取该礼包", i) : e > r ? (i = Math.floor(e / r) + "分钟后才可领取该礼包", i) : (i = "即将领取该礼包", i)
    }

    function M(t, n) {
        e(".ex-con").html(t), e(".ex-info").html("1758客户端玩游戏更流畅、可全屏");
        if (n == "iphoneclient" || n == "androidclient")e(".ex-load").html("知道了"), e(".ex-load").removeAttr("href");
        e(".tip").removeClass("gone")
    }

    function _(t, n) {
        var r = "http://wx.1758.com/game/api/app/gif/apply?gifId=" + t;
        e.get(r, function (e) {
            e.code == -1 && (location.href = "http://wx.1758.com/game/platform/v1.0/user/flogin?appKey=ba0ab54c1eb63a776fa477153a0a354b"), e.code == 0 && P("领号成功", e.cdkey, t, 0, n)
        })
    }

    function D(t, n) {
        var r = "http://wx.1758.com/game/api/app/gif/tao?gifId=" + t;
        e.get(r, function (e) {
            e.code == -1 && (location.href = "http://wx.1758.com/game/platform/v1.0/user/flogin?appKey=ba0ab54c1eb63a776fa477153a0a354b"), e.code == 0 && P("淘号成功", e.cdkey, t, 1, n)
        })
    }

    function P(e, t, n, r, i) {
        var s = "http://wx.1758.com/game/h5/giftinfo.htm?cdkey=" + t + "&aid=" + n + "&flag=" + r + "&exclusive=" + i;
        location.href = s + "&tp=outer&client=1&tp=full&ex1758=1"
    }

    function H() {
        var t = '<div class="tip"><div class="tip-dialog"><div class="tip-wrapper"><div class="tip-content tip-exclusive"><div class="tip-body"><p class="ex-con">请通过1758客户端领取专属礼包</p><span class="ex-inner"><span class="ex-info">您还没有安装1758客户端？</span><a class="ex-load" href="http://m.1758.com/game/download.htm">立即下载</a></span></div></div></div></div></div>';
        e(".ex-con").html('<span style="color: #71A540;">专属礼包</span>需通过1758客户端领取'), e(".ex-info").html("您还没有安装1758客户端？"), e(".tip").removeClass("gone")
    }

    var o = "hot", u, a = "点击加载更多", f = "加载中...";
    l(), e(document).on("click", ".dk", function () {
        o = e(this).attr("data-track");
        var t = e(this).attr("data-type");
        p(e(this)), h(o)
    }), e(document).on("click", ".more-info", function () {
        var t = e(this).attr("data-track"), n = e(this).attr("data-num");
        switch (t) {
            case"hot":
                y(n);
                break;
            case"newgame":
                v(n);
                break;
            case"gift":
                m(n)
        }
    }), e(document).on("click", "#new-more", function () {
        location.href = "http://wx.1758.com/game/h5/page/recommendgame.htm?ex1758=1&tp=full&yn=小编推荐&title=小编推荐"
    }), e(document).on("click", ".notime-btn", function () {
        var t = e(this).attr("data-value"), n = e(this).attr("data-time"), i = e(this).prev().find(".g-fail-day").html(), s = r.userTerminal();
        t == "1" ? s == "weixin" || s == "others" ? H() : A(n, i, s) : A(n, i, s)
    }), e(document).on("click", ".end-btn", function () {
        var t = e(this).attr("data-value"), n = e(this).prev().find(".g-fail").html(), i = r.userTerminal();
        t == "1" ? i == "weixin" || i == "others" ? H() : M(n, i) : M(n, i)
    }), e(document).on("click", "#gift-list .linghao", function () {
        var t = e(this).attr("data-num"), n = e(this).attr("data-value"), i;
        n == "1" ? (i = r.userTerminal(), i == "weixin" || i == "others" ? H() : _(t, n)) : n == "0" && _(t, n)
    }), e(document).on("click", "#gift-list .taohao", function () {
        var t = e(this).attr("data-num"), n = e(this).attr("data-value"), i;
        n == "1" ? (i = r.userTerminal(), i == "weixin" || i == "others" ? H() : D(t, n)) : n == "0" && D(t, n)
    }), e(document).on("click", ".tip", function (t) {
        e(".tip").addClass("gone")
    })
}), define("view/index", function () {
});