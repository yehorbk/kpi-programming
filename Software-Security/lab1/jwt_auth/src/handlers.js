const path = require('path');

const SessionManager = require('./session-manager');

const users = require('./users');
const { sign, verify } = require('./auth');

module.exports = (sessionManager => {
  const findUser = ({ login, password }) => users
    .find(user => user.login === login && user.password === password);

  const parsePayload = bearer => {
    if (!bearer) return;
    const token = bearer.split(' ')[1];
    if (!token) return;
    return verify(token);
  }

  const root = (req, res) => {
    const bearer = req.headers['authorization'];
    const payload = parsePayload(bearer);
    if (payload) {
      const { login, password, sessionId } = payload;
      const user = findUser({ login, password });
      const session = sessionManager.get(sessionId);
      if (!user || !session) {
        res.status(403).send();
      } else {
        const { username } = user;
        res.json({ username });
      }
      return;
    }
    res.sendFile(path.resolve(__dirname, '..', 'public/index.html'));
  };

  const login = (req, res) => {
    const { login, password } = req.body;
    const user = findUser({ login, password });
    if (!user) {
      res.status(401).send();
      return;
    }
    const { username } = user;
    const sessionId = sessionManager.init(username);
    const token = sign({ login, password, sessionId });
    res.json({ token });
  };

  const logout = (req, res) => {
    const bearer = req.headers['authorization'];
    const payload = parsePayload(bearer);
    if (!payload) {
      res.status(400).send();
      return;
    }
    const { sessionId } = payload;
    sessionManager.destroy(sessionId);
    res.status(200).send();
  };

  return { root, login, logout };
})(new SessionManager());
