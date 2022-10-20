#include "Product.h"

Product::Product(uint16_t id, const std::string &name, float price, uint16_t tva, const std::string &expirationDate)
    : m_Id{id}, m_Name{name}, m_Price{price}, m_Tva{tva}, m_ExpirationDate{expirationDate}
{
}

Product::Product(uint16_t id, const std::string &name, float price, uint16_t tva, ProductType type)
    : m_Id{id}, m_Name{name}, m_Price{price}, m_Tva{tva}, m_Type{type}
{
}

uint16_t Product::GetId() const
{
      return this->m_Id;
}

std::string Product::GetName() const
{
      return this->m_Name;
}

float Product::GetPrice() const
{
      return this->m_Price + this->m_Price * (this->m_Tva / 100.0f);
}

uint16_t Product::GetTva() const
{
      return this->m_Tva;
}

std::string Product::GetExpirationDate() const
{
      return this->m_ExpirationDate;
}

ProductType Product::GetType() const
{
      return this->m_Type;
}
