/*
https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/?envType=daily-question&envId=2025-03-21
*/

/**
 * @param {string[]} recipes
 * @param {string[][]} ingredients
 * @param {string[]} supplies
 * @return {string[]}
 */
var findAllRecipes = function(recipes, ingredients, supplies) {
    let alreadyAvailableSuppliesMap=new Map();
    let lengthSupplies=supplies.length;
    for(let i=0; i<lengthSupplies; ++i){
        let supply=supplies[i];
        if(!alreadyAvailableSuppliesMap.has(supply)){
            alreadyAvailableSuppliesMap.set(supply, supply);
        }
    }
    let lengthOfRecipes=recipes.length;
    let resultantRecipesToCreate=[];
    let alreadySeenRecipes=new Set();
    let maxIterationRequired=101;
    while(maxIterationRequired--){
        for(let i=0; i<lengthOfRecipes; ++i){
            if(!alreadySeenRecipes.has(i)){
                let currentRecipe=recipes[i];
                let currentlyNeededIngredients=ingredients[i];
                let currentListSize=currentlyNeededIngredients.length;
                let canRecipeBeMade=true;
                for(let j=0; j<currentListSize; ++j){
                    let currentIngredient=currentlyNeededIngredients[j];
                    if(!alreadyAvailableSuppliesMap.has(currentIngredient)){
                        canRecipeBeMade=false;
                        break;
                    }
                }
                if(canRecipeBeMade){
                    alreadyAvailableSuppliesMap.set(currentRecipe, currentRecipe);
                    resultantRecipesToCreate.push(currentRecipe);
                    alreadySeenRecipes.add(i);
                }
            }
        }
    }
    return resultantRecipesToCreate;
};
