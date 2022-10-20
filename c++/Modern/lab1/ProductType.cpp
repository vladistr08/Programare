#include "ProductType.h"

ProductType convert(const std::string &rawString)
{

      if (rawString == "PersonalHygiene")
      {
            return ProductType::PersonalHygiene;
      }
      else if (rawString == "SmallAppliences")
      {
            return ProductType::SmallAppliences;
      }
      else if (rawString == "Clothing")
      {
            return ProductType::Clothing;
      }
      throw std::exception{"Unknown product type..."};
}