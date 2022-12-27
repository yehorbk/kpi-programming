const express = require('express');
const bodyParser = require('body-parser');

const { root, login, logout } = require('./src/handlers');

// BAD CODE START
process.env = {
  SECRET_KEY: 'secret_key',
};
// BAD CODE END

const PORT = 3000;

const app = express();

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

app.get('/', root);
app.get('/logout', logout);
app.post('/api/login', login);

app.listen(PORT, () => {
  console.log(`Server started on port ${PORT}`);
});
