//BACKEND
console.log("Server test");
const express = require('express');
const app = express();
app.use(express.static('public'));
const bodyParser = require('body-parser');
app.use(bodyParser.json());
const port = 4000; //asigno el puerto

var SENSOR = {"temp1":"","Hum1":"","Calidad":""}




app.get('/', (req, res) => {
    //res.send("Petición 1 recibida")
    res.sendFile(__dirname + "/login.html");

});


        

app.post('/data',(req,res) => {
    var data = JSON.parse(JSON.stringify(req.body));
    console.log('datos Sensor recibidos');
    console.log('Temp1:' + data.temperatura);
    console.log('Presion1:' + data.humedad);
    console.log('Calidad de aire:' + data.calidad);   
    
    SENSOR.temp1 = data.temperatura;
    SENSOR.Hum1 = data.humedad;    
    SENSOR.Calidad= data.calidad;  
    
        
    res.status(200);
    res.send('OK');
});

app.get('/sens',(req, res) => {
    var data = {"temp1":SENSOR.temp1,"Hum1":SENSOR.Hum1,"Calidad":SENSOR.Calidad};  
    res.status(200);
    res.send(data); 

    datos();   
});




app.listen(port, () => {
    console.log("Server in http://localhost:" + port)


 }); //aquí pondré la funcionalidad
