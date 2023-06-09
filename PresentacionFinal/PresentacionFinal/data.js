


function datos(){
    $.get({
        url: "/sens",
        success: function(datosRes, status){            
            document.getElementById('temp1').innerHTML = datosRes.temp1;
            document.getElementById('humedad1').innerHTML = datosRes.Hum1;   
            document.getElementById('ca1').innerHTML = datosRes.Calidad;            
        }
    });
}

