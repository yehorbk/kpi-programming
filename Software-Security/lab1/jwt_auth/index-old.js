const uuid = require('uuid');
const jwt = require('jsonwebtoken');

const express = require('express');
const onFinished = require('on-finished');
const bodyParser = require('body-parser');

const path = require('path');
const fs = require('fs');

const port = 3000;
const app = express();

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

const SECRET_KEY = 'secret_key';
const SESSION_KEY = 'Authorization';

const users = [
  {
    login: 'Login',
    password: 'Password',
    username: 'Username',
  },
  {
    login: 'Login1',
    password: 'Password1',
    username: 'Username1',
  },
];

class Session {
  #sessions = {}

  constructor() {
    try {
      this.#sessions = fs.readFileSync('./sessions.json', 'utf8');
      this.#sessions = JSON.parse(this.#sessions.trim());
    } catch (e) {
      this.#sessions = {};
    }
  }

  #storeSessions() {
    fs.writeFileSync('./sessions.json', JSON.stringify(this.#sessions), 'utf-8');
  }

  set(key, value) {
    if (!value) {
      value = {};
    }
    this.#sessions[key] = value;
    this.#storeSessions();
  }

  get(key) {
    return this.#sessions[key];
  }

  init(req) {
    const { login, password } = req.body;
    const sessionId = login && password
      ? jwt.sign({ login, password }, SECRET_KEY)
      : uuid.v4();
    this.set(sessionId);
    return sessionId;
  }

  destroy(req) {
    const sessionId = req.sessionId;
    delete this.#sessions[sessionId];
    this.#storeSessions();
  }
}

const sessions = new Session();

app.use((req, res, next) => {
  let currentSession = {};
  let sessionId = req.get(SESSION_KEY);
  if (sessionId) {
    currentSession = sessions.get(sessionId);
    if (!currentSession) {
      currentSession = {};
      sessionId = sessions.init(req);
    }
  } else {
    sessionId = sessions.init(req);
  }
  req.session = currentSession;
  req.sessionId = sessionId;
  onFinished(req, () => {
    const currentSession = req.session;
    const sessionId = req.sessionId;
    sessions.set(sessionId, currentSession);
  });
  next();
});

app.get('/', (req, res) => {
  if (req.session.username) {
    return res.json({
      username: req.session.username,
      logout: 'http://localhost:3000/logout'
    });
  }
  res.sendFile(path.join(__dirname, 'index.html'));
});

app.get('/logout', (req, res) => {
  sessions.destroy(req, res);
  res.redirect('/');
});

app.post('/api/login', (req, res) => {
  const { login, password } = req.body;
  const user = users.find((user) => {
    if (user.login == login && user.password == password) {
      return true;
    }
    return false
  });
  if (user) {
    req.session.username = user.username;
    req.session.login = user.login;
    res.json({ token: req.sessionId });
  }
  res.status(401).send();
});

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
});
