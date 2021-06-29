let testNum = 1;

function assert(a, b, msg) {
  const succeed = a ===  b;
  if(succeed) {
    console.log(`%cTest ${testNum++} (${msg}) passed`, 'color: #2ecc71; font-size: 16px');
  } else {
    console.error(`%cTest ${testNum++}: error with ${msg}`, 'font-size: 16px');
  }
}

function fakeValidator(field, ...conditions) {
  let successful = true;
  const fieldValue = field.value.trim();
  conditions.forEach(condition => {
    const result = condition(fieldValue);
    if(!result.successful) {
      successful = false;
    }
  })
  return successful;
} 

// minLength tests
{
  console.log('%cTesting minimum field length checker', 'font-size: 20px');

  const testFn = minLength.bind(null, 4);

  
  const tooShortData = 'abc';
  assert(testFn(tooShortData).successful ,  false, 'too short field value')

  
  const goodData = 'abcd';
  assert(testFn(goodData).successful ,  true, 'good data field value');
}

// maxLength tests
{
  console.log('%cTesting maximum field length checker', 'font-size: 20px');

  const testFn = maxLength.bind(null, 10);

  
  const tooLongData = '12345678910';
  assert(testFn(tooLongData).successful ,  false, 'too long field value');

  
  const goodData = '1234567890';
  assert(testFn(goodData).successful ,  true, 'good data field value');
}

// empty field tests 
{
  console.log('%cTesting empty field checker', 'font-size: 20px');

  const empty = '';
  assert(isEmpty(empty).successful ,  false, 'empty string given');

  
  const good = 'asdA23sdds';
  assert(isEmpty(good).successful ,  true, 'good data field value');
}

// restricted symbols including tests
{
  console.log('%cTesting restricted symbols including checker', 'font-size: 20px');

  const testFn = restrictedSymbols.bind(null, '$%^&*(');
  
  const badData = 'df123$sfd';
  assert(testFn(badData).successful ,  false, 'field value with restricted symbols ');

  
  const goodData = 'df123sfd';
  assert(testFn(goodData).successful ,  true, 'good data field value');
}

// password compare tests
{
  console.log('%cTesting password comparer', 'font-size: 20px');
  password.value = 'abcdefg';

  const badPassword = 'abcdEfg';
  assert(compPasswords(badPassword).successful ,  false, 'different password given');

  
  const goodData = 'abcdefg';
  assert(compPasswords(goodData).successful ,  true, 'good data field value');
}

// email validator tests 
{
  console.log('%cTesting email validator', 'font-size: 20px');
  
  const badEmail = 'dfjkdl@dss';
  assert(validateEmail(badEmail).successful ,  false, 'incorrect email given');

  
  const goodData = 'dfjkdl@dss.com';
  assert(validateEmail(goodData).successful ,  true, 'good data field value');
}

// full validator tests
{
  console.log('%cTesting full validator', 'font-size: 20px');
  username.value = 'Hey';

  const expectedFalseForMinlength = validator(username, minLength.bind(null, 4), restrictedSymbols.bind(null, restricted + '@'), isEmpty, maxLength.bind(null, 16));
  assert(expectedFalseForMinlength ,  false, 'Too short field value given');
  
  username.value = 'He&y';
  const expectedFalseForRestrictedSymbols = validator(username, minLength.bind(null, 4), restrictedSymbols.bind(null, restricted + '@'), isEmpty, maxLength.bind(null, 16));
  assert(expectedFalseForRestrictedSymbols ,  false, 'Restricted symbols used');
  
  username.value = 'HeyGood';
  const expectedTrueUsername = validator(username, minLength.bind(null, 4), restrictedSymbols.bind(null, restricted + '@'), isEmpty, maxLength.bind(null, 16));
  assert(expectedTrueUsername ,  true, 'good username field value');

  email.value = "hello@streamflow.com";
  const expectedTrueEmail = validator(email, restrictedSymbols.bind(null, restricted), validateEmail, isEmpty);
  assert(expectedTrueEmail ,  true, 'good email field value');

  password.value = "abcd1234";
  const expectedTruePassword = validator(password, minLength.bind(null, 6), restrictedSymbols.bind(null, restricted + '@'), isEmpty);
  assert(expectedTruePassword ,  true, 'good password field value');

  password2.value = "abcd1234";
  const expectedTruePasswordRepeat = validator(password2, compPasswords, isEmpty);
  assert(expectedTruePasswordRepeat ,  true, 'good repeat password field value');

}

// fake validator tests
{
  console.log('%cTesting fake full validator', 'font-size: 20px');

  const fakeUsernameField = {
    value: 'Hey'
  };
  
  const expectedFalseForMinlength = fakeValidator(fakeUsernameField, minLength.bind(null, 4), restrictedSymbols.bind(null, restricted + '@'), isEmpty, maxLength.bind(null, 16));
  assert(expectedFalseForMinlength ,  false, 'Too short field value');
  
  
  fakeUsernameField.value = 'He&y';
  const expectedFalseForRestrictedSymbols = fakeValidator(fakeUsernameField, minLength.bind(null, 4), restrictedSymbols.bind(null, restricted + '@'), isEmpty, maxLength.bind(null, 16));
  assert(expectedFalseForRestrictedSymbols ,  false, 'Restricted symbols used');

  
  fakeUsernameField.value = 'HeyGood';
  const expectedTrueUsername = fakeValidator(fakeUsernameField, minLength.bind(null, 4), restrictedSymbols.bind(null, restricted + '@'), isEmpty, maxLength.bind(null, 16));
  assert(expectedTrueUsername ,  true, 'good username field value');
}