const jwt = require('jsonwebtoken');

const sign = payload =>
  jwt.sign(payload, process.env.SECRET_KEY);

const verify = token =>
  jwt.verify(token, process.env.SECRET_KEY);

module.exports = { sign, verify };
