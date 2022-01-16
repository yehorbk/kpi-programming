'use strict';

document.addEventListener('click', event => {
  const target = event.target;
  if (target.dataset.like !== undefined) {
    if (!target.value) {
      target.value = 0;
    }
    target.innerText = `${++target.value}+`;
  }
});
