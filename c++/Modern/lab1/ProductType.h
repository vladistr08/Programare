#ifndef PRODUCTTYPE_H
#define PRODUCTTYPE_H

#include <cstdint>
#include <string>

enum class ProductType : uint8_t
{
      PersonalHygiene,
      SmallAppliences,
      Clothing
};

ProductType convert(const std::string &rawType);

#endif // PRODUCTTYPE_H