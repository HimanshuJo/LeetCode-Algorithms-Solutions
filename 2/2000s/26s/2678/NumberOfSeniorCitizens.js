/*
https://leetcode.com/problems/number-of-senior-citizens/description/?envType=daily-question&envId=2024-08-01
*/

/**
 * @param {string[]} details
 * @return {number}
 */
var countSeniors = function(details) {
    let resultantCitizens=0;
    let lengthOfDetails=details.length;
    for(let i=0; i<lengthOfDetails; ++i){
        let currentCitizenDetails=details[i];
        let onesDigitInAge=parseInt(currentCitizenDetails[11], 10), zerothDigitInAge=parseInt(currentCitizenDetails[12], 10);
        if(onesDigitInAge>=6){
            if(zerothDigitInAge===0){
                if(onesDigitInAge!==6) resultantCitizens++;
            } else resultantCitizens++; 
        }
    }
    return resultantCitizens;
};