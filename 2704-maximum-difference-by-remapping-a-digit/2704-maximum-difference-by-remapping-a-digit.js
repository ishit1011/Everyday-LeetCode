/**
 * @param {number} num
 * @return {number}
 */
var minMaxDifference = function(num) {
    const number1 = num.toString().split('');
    const number2 = num.toString().split('');

    let maxReplaced, maxIdx;
    for (let i = 0; i < number1.length; i++) {
        if (number1[i] !== '9') {
            maxReplaced = number1[i];
            maxIdx = i;
            number1[i] = '9';
            break;
        }
    }

    if (maxIdx !== undefined) {
        for (let i = maxIdx + 1; i < number1.length; i++) {
            if (number1[i] === maxReplaced) {
                number1[i] = '9';
            }
        }
    }

    let minReplaced, minIdx;
    for (let i = 0; i < number2.length; i++) {
        if (number2[i] !== '0') {
            minReplaced = number2[i];
            minIdx = i;
            number2[i] = '0';
            break;
        }
    }

    if (minIdx !== undefined) {
        for (let i = minIdx + 1; i < number2.length; i++) {
            if (number2[i] === minReplaced) {
                number2[i] = '0';
            }
        }
    }

    const ans = +number1.join('') - +number2.join('');
    return ans;
};