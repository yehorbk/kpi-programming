const restricted = '!#№$;% ^":]&*()+=`~[{}\'/-,';

function setSuccess(input) {
  const formControl = input.parentElement;
  formControl.className = 'form-control success';
}

function setError(input, message) {
  const formControl = input.parentElement;
  const small = formControl.querySelector('small');
  small.innerText = message;
  formControl.className = 'form-control error';
}

function validator(field, ...conditions) {
  let successful = true;
  const fieldValue = field.value.trim();
  conditions.forEach(condition => {
    const result = condition(fieldValue);
    if(!result.successful) {
      setError(field, result.errorMessage);
      successful = false;
    }
  })
  if(successful) setSuccess(field);
  return successful;
} 

const minLength = (N, data) => ({
  successful: (data ? data.length >= N : false),
  errorMessage: `Минимальная длина - ${N} символа(-ов)`
});

const maxLength = (N, data) => ({
  successful: (data ? data.length <= N : false),
  errorMessage: `Максимальная длина - ${N} символа(-ов)`
});

const isEmpty = data => ({
  successful: data.length !== 0,
  errorMessage: `Пустое поле`
});

const restrictedSymbols = (symbols, data) => {
  let successful = true;
  const found = [];
  data.split('').forEach(symbol => {
    symbols.split('').forEach(char => {
      if(char === symbol) {
        if(!found.includes(symbol) && symbol !== ' ') found.push(symbol);
        successful = false;
      }
    })
  })
  const ending = found.length === 1 ? '' : 'ы';
  return ({
    successful,
    errorMessage: `Пробелы и символ${ending} ${found.join('   ')} запрещен${ending}`
  })
}

const compPasswords = p2 => ({
  successful: password.value.trim() === p2,
  errorMessage: 'Пароли не совпадают'
})

function validateEmail(data) {
  const re = /\S+@\S+\.\S+/;
  return ({
    successful: re.test(data),
    errorMessage: 'Некорректный email'
  })
}
    