// FIXME: no path(index.html) does not get parsed
function add_active() {
    var current = location.pathname.split('/')[1];
    if (current === "") return;
    var menu_items = document.querySelectorAll('a.nav-link');
    for (var i = 0, len = menu_items.length; i < len; i++) {
        if (menu_items[i].getAttribute("href").indexOf(current) !== -1) {
            menu_items[i].className += " active";
        }
    }
};

document.addEventListener("DOMContentLoaded", function () {
    add_active();
});