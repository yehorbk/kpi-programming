const form = document.getElementById('form');
const username = document.getElementById('username');
const email = document.getElementById('email');
const password = document.getElementById('password');
const password2 = document.getElementById('password2');

form.addEventListener('submit', e => {
  e.preventDefault();
  validateData();
});

const toValidate = [
  {
    field: username,
    conditions: [minLength.bind(null, 4), restrictedSymbols.bind(null, restricted + '@'), isEmpty, maxLength.bind(null, 16), isEmpty]
  },
  {
    field: email,
    conditions: [restrictedSymbols.bind(null, restricted), validateEmail, isEmpty]
  },
  {
    field: password,
    conditions: [minLength.bind(null, 6), restrictedSymbols.bind(null, restricted + '@'), isEmpty]
  },
  {
    field: password2,
    conditions: [compPasswords, isEmpty]
  },
]

function validateData() {
  let succeed = true;
  toValidate.forEach(obj => {
    const res = validator(obj.field, ...obj.conditions);
    if(!res) succeed = false;
  })
}