//BACKEND
console.log("Server test");
const express = require('express');
const app = express();
app.use(express.static('public'));
const bodyParser = require('body-parser');
app.use(bodyParser.json());
const port = 3000; //asigno el puerto
var flag_session = 0;


var SENSOR = {"temp1":"","Hum1":"","Calidad":""};


app.get('/', (req, res) => {
    //res.send("Petición 1 recibida")
    res.sendFile(__dirname + "/public/iot.html");

});


        

app.post('/data',(req,res) => {
    var data = JSON.parse(JSON.stringify(req.body));
    console.log('datos Sensor recibidos');
    console.log('Temp1:' + data.temp1);
    console.log('Humedad1:' + data.Hum1);
    console.log('Calidad de aire:' + data.Calidad);   
    
    SENSOR.temp1 = data.temp1;
    SENSOR.Hum1 = data.Hum1;    
    SENSOR.Calidad= data.Calidad;  
    res.status(200);
    res.send('OK');
});

app.get('/sens',(req, res) => {
    var data = {"temp1":SENSOR.temp1,"Hum1":SENSOR.Hum1,"Calidad":SENSOR.Calidad};  
    res.status(200);
    res.send(data); 
    
});




app.listen(port, () => {
    console.log("Server in http://localhost:" + port)


 }); //aquí pondré la funcionalidad
