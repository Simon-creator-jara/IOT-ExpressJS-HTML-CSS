var A = "texto1";
var B = 10.5;
var USR = { 'usr': "", 'pass': "" };
var d = new Date();


function enviar(){
    USR.usr = document.getElementById('user').value;
    USR.pass = document.getElementById('pass').value;
    console.log(USR);
    //Petición POST
    $.post({
        url: "/login",
        data: JSON.stringify(USR), //convierto el vector a texto para enviarlo
        contentType: "application/json", //le digo la forma en la que va a llegar
        success: function (datosRes, staus) {
            if (datosRes === "OK") {
                window.location.replace("/web");
            } else if (datosRes === "ERROR") {
                alert("Acceso Denegado")
            }


        }

    });
}

