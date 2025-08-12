/*
 * Copyright (C) 2025 YANG Rui <yangrui1028@gmail.com>
 *
 * This file is part of DesignPatternsCPP.
 *
 * Licensed under the GNU General Public License v3.0 or later.
 * See <https://www.gnu.org/licenses/>.
 */

#ifndef PRODUCT_TENNIS_SHOES_FACTORY_HPP
#define PRODUCT_TENNIS_SHOES_FACTORY_HPP

#include "tennis_shoes.hpp"

#include <memory>

class TennisShoesFactory
{
public:
    // Factory method to create TennisShoes
    virtual std::shared_ptr<TennisShoes> createTennisShoes() const = 0;
};

enum class TennisShoesBrand : uint8_t;

class TennisShoesFactoryWithBrandParameter
{
public:
    // Factory method to create TennisShoes with a specific brand
    virtual std::shared_ptr<TennisShoes> createTennisShoes(TennisShoesBrand brand) const = 0;
};

template <class TheShoes>
class ConcreteTennisShoesFactory : public TennisShoesFactory
{
public:
    // Override the factory method to create specific TennisShoes
    std::shared_ptr<TennisShoes> createTennisShoes() const override {
        return std::make_shared<TheShoes>();
    }
};

#endif // PRODUCT_TENNIS_SHOES_FACTORY_HPP
