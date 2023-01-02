const express = require('express');
const cors = require('cors');
const axios = require('axios');

const app = express();
app.use(
    cors({
        origin: '*'
    })
);

app.get('/pojazdy', async (req, res) => {
    const wojID = req.query.wojID || '10';
    const dataOd = req.query.dataOd || '20220128';

    const data = await axios.get('https://api.cepik.gov.pl/pojazdy?wojewodztwo=' + wojID + '&data-od=' + dataOd)
        .then(response => response.data)
        .catch(err => console.log(err));
    res.json(data)
;});

app.get('/slowniki/wojewodztwa', async (req, res) => {
    const data = await axios.get('https://api.cepik.gov.pl/slowniki/wojewodztwa')
        .then(response => response.data)
        .catch(err => console.log(err));
    res.json(data)
;});


app.listen(3000, console.log('Staring an API Proxy for the Angular app..'));
