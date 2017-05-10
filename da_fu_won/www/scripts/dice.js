function dice() {
    var w = 0;
    //i=parseInt(document.getElementById("inp").num.value);
    //i=eval(document.getElementById("inp").num.value);
    w = Math.floor(Math.random() * 6) + 1;
    document.getElementById("ans").innerHTML = "擲出 " + w + " 點";
    alert("擲出 " + w + " 點");

    if (w == 1) {
        window.location = "choice.html";
    } else if (w == 2) {
        window.location = "fillin.html";
    } else if (w == 3) {
        window.location = "speak.html";
    } else if (w == 4) {
        window.location = "";
    }
}

