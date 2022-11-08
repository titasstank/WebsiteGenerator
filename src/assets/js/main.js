$(document).ready(function () {
    var pathname = window.location.pathname,
        pages = ['index', 'freshmore', 'sophomore', 'junior', 'senior'];

    $('.nav-item').each(function (i) {
        if (pathname.includes(pages[i])) this.addClass('active');
        else if (this.className.includes('active')) this.removeClass('active');
    });
})