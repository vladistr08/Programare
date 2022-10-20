#ifndef PRODUCT_H
#define PRODUCT_H

#include <cstdint>
#include <string>
#include "ProductType.h"

class Product
{
public:
      Product(uint16_t id, const std::string &name, float price, uint16_t tva, const std::string &expirationDate);
      Product(uint16_t id, const std::string &name, float price, uint16_t tva, ProductType type);
      // Product(const Product &toCopyProduct) = default;

      // Product &operator=(const Product &toCopyProduct);

      //~Product();

      uint16_t GetId() const;
      std::string GetName() const;
      float GetPrice() const;
      uint16_t GetTva() const;
      std::string GetExpirationDate() const;
      ProductType GetType() const;

private:
      uint16_t m_Id;
      std::string m_Name;
      float m_Price;
      uint16_t m_Tva;
      std::string m_ExpirationDate;
      ProductType m_Type;
};

#endif // PRODUCT_H