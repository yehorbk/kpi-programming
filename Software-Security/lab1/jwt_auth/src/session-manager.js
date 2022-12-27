const fs = require('fs');
const uuid = require('uuid');

const FILE_NAME = './sessions.json';
const ENCODING = 'utf8';

class SessionManager {
  constructor() {
    try {
      const raw = fs.readFileSync(FILE_NAME, ENCODING);
      this.sessions = JSON.parse(raw.trim());
    } catch (error) {
      this.sessions = {};
    }
  }

  store() {
    const raw = JSON.stringify(this.sessions);
    fs.writeFileSync(FILE_NAME, raw, ENCODING);
  }

  init(value) {
    const key = uuid.v4();
    this.set(key, value);
    return key;
  }

  get(key) {
    return this.sessions[key];
  }

  set(key, value) {
    this.sessions[key] = value;
    this.store();
  }

  destroy(key) {
    delete this.sessions[key];
    this.store();
  }
}

module.exports = SessionManager;
