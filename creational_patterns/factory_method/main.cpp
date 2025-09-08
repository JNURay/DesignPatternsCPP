// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#include "tennis_shoes.hpp"
#include "tennis_shoes_factory.hpp"

#include <iostream>

class NikeTennisShoes : public TennisShoes
{
public:
    void wear() const override {
        std::cout << "Nike shoes have a such stylish design" << std::endl;
    }
};

class AsicsTennisShoes : public TennisShoes
{
public:
    void wear() const override {
        std::cout << "Asics shoes are known for their comfort and support" << std::endl;
    }
};

class NikeTennisShoesFactory : public TennisShoesFactory
{
public:
    std::shared_ptr<TennisShoes> createTennisShoes() const override {
        return std::make_shared<NikeTennisShoes>();
    }
};

class AsicsTennisShoesFactory : public TennisShoesFactory
{
public:
    std::shared_ptr<TennisShoes> createTennisShoes() const override {
        return std::make_shared<AsicsTennisShoes>();
    }
};

enum class TennisShoesBrand : uint8_t {
    Nike,
    Asics
};

class TennisShoesFactoryWithBrand : public TennisShoesFactoryWithBrandParameter
{
public:
    std::shared_ptr<TennisShoes> createTennisShoes(TennisShoesBrand brand) const override {
        switch (brand) {
            case TennisShoesBrand::Nike:
                return std::make_shared<NikeTennisShoes>();
            case TennisShoesBrand::Asics:
            default:
                return std::make_shared<AsicsTennisShoes>();
        }
    }
};

int main() {
    std::cout << "standard factory method usage" << std::endl;
    std::unique_ptr<TennisShoesFactory> factory;

    factory = std::make_unique<NikeTennisShoesFactory>();
    auto nikeShoes = factory->createTennisShoes();
    nikeShoes->wear();

    factory = std::make_unique<AsicsTennisShoesFactory>();
    auto asicsShoes = factory->createTennisShoes();
    asicsShoes->wear();

    std::cout <<std::endl;
    std::cout << "factory with brand parameter usage" << std::endl;
    std::unique_ptr<TennisShoesFactoryWithBrandParameter> brandFactory;

    brandFactory = std::make_unique<TennisShoesFactoryWithBrand>();
    auto brandedNikeShoes = brandFactory->createTennisShoes(TennisShoesBrand::Nike);
    brandedNikeShoes->wear();

    auto brandedAsicsShoes = brandFactory->createTennisShoes(TennisShoesBrand::Asics);
    brandedAsicsShoes->wear();

    std::cout <<std::endl;
    std::cout << "template factory usage, no need  to define a specific factory class" << std::endl;
    ConcreteTennisShoesFactory<NikeTennisShoes> nikeTemplateFactory;
    auto nikeTemplateShoes = nikeTemplateFactory.createTennisShoes();
    nikeTemplateShoes->wear();

    ConcreteTennisShoesFactory<AsicsTennisShoes> asicsTemplateFactory;
    auto asicsTemplateShoes = asicsTemplateFactory.createTennisShoes();
    asicsTemplateShoes->wear();

    return 0;
}
