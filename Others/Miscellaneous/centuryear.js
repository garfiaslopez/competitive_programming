function centuryFromYear(year) {
    if (year % 10 === 0) {
        return Math.floor(year / 100);
    } else {
        return Math.floor(year / 100) + 1;
    }
}


console.log(centuryFromYear(1905));
