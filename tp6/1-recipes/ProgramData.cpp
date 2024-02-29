#include "ProgramData.hpp"

void ProgramData::add_material(std::string name)
{
    _inventory.emplace_back(std::make_unique<Material>(std::move(name)));
}

void ProgramData::get_materials(std::vector<const Material *> &materials) const
{
    for (const auto &material : _inventory)
    {
        materials.emplace_back(material.get());
    }
}

void ProgramData::register_recipe(std::vector<std::string> materials, std::vector<std::string> products)
{
    auto &new_recipe = _recipes.emplace_back(std::make_unique<Recipe>(std::move(materials), std::move(products)));
    std::cout << "Recipe " << *new_recipe.get() << " has been registered" << std::endl;
}

void ProgramData::collect_doable_recipes(std::vector<const Recipe *> &recipes) const
{
    for (const auto &recipe : _recipes)
    {
        bool doable = true;
        for (const auto &material : recipe->get_materials())
        {
            bool found = false;
            for (const auto &inventory_material : _inventory)
            {
                if (material == inventory_material->get_name())
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                doable = false;
                break;
            }
        }
        if (doable)
        {
            recipes.emplace_back(recipe.get());
        }
    }
}

ProductionResult ProgramData::produce(size_t recipe_id)
{
    ProductionResult result;
    return result;
}