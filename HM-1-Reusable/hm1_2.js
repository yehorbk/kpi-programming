'use strict'

const range = (start, end) => {
    for (let i = start; i <= end; i++) {
        if (i % 2 == 1) {
            console.log(i);
        }
    }
}

range(15, 30);