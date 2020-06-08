'use strict';

const seq = f => g => x => typeof x === 'function' ? seq(seq(f)(g))(x) : f(g(x));

module.exports = { seq };
