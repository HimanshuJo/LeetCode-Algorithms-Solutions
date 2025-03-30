/*
https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/?envType=daily-question&envId=2025-03-21
*/

class Solution {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        HashMap<String, String>alreadyAvailableSuppliesMap=new HashMap<>();
        for(String supply: supplies){
            if(!alreadyAvailableSuppliesMap.containsKey(supply)){
                alreadyAvailableSuppliesMap.put(supply, supply);
            }
        }
        int lengthOfRecipes=recipes.length;
        ArrayList<String>resultantRecipesToCreate=new ArrayList<>();
        HashSet<Integer>alreadySeenRecipes=new HashSet<>();
        int maxIterationRequired=101;
        while(maxIterationRequired-- >0){
            for(int i=0; i<lengthOfRecipes; ++i){
                if(!alreadySeenRecipes.contains(i)){
                    String currentRecipe=recipes[i];
                    List<String>currentlyNeededIngredients=ingredients.get(i);
                    int currentListSize=currentlyNeededIngredients.size();
                    boolean canRecipeBeMade=true;
                    for(int j=0; j<currentListSize; ++j){
                        String currentIngredient=currentlyNeededIngredients.get(j);
                        if(!alreadyAvailableSuppliesMap.containsKey(currentIngredient)){
                            canRecipeBeMade=false;
                            break;
                        }
                    }
                    if(canRecipeBeMade){
                        alreadyAvailableSuppliesMap.put(currentRecipe, currentRecipe);
                        resultantRecipesToCreate.add(currentRecipe);
                        alreadySeenRecipes.add(i);
                    }
                }
            }
        }
        return resultantRecipesToCreate;
    }
}
