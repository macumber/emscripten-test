/***********************************************************************************************************************
 *  OpenStudio(R), Copyright (c) 2008-2018, Alliance for Sustainable Energy, LLC. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 *  following conditions are met:
 *
 *  (1) Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 *  disclaimer.
 *
 *  (2) Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *  following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *  (3) Neither the name of the copyright holder nor the names of any contributors may be used to endorse or promote
 *  products derived from this software without specific prior written permission from the respective party.
 *
 *  (4) Other than as required in clauses (1) and (2), distributions in any form of modifications or other derivative
 *  works may not use the "OpenStudio" trademark, "OS", "os", or any other confusingly similar designation without
 *  specific prior written permission from Alliance for Sustainable Energy, LLC.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER, THE UNITED STATES GOVERNMENT, OR ANY CONTRIBUTORS BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **********************************************************************************************************************/

#include "Json.hpp"

#include "Assert.hpp"
//#include "Compare.hpp"
#include "Logger.hpp"
//#include "PathHelpers.hpp"
//#include "FilesystemHelpers.hpp"
//#include "String.hpp"

#include <jsoncpp/json.h>

namespace openstudio {

// assert key is present
void assertKey(const Json::Value& value, const std::string& key)
{
  if (!checkKey(value, key)){
    throw std::runtime_error(std::string("Cannot find key '" + key + "'"));
  }
}

// assert type is correct if key is present
void assertType(const Json::Value& value, const std::string& key, const Json::ValueType& valueType)
{
  if (!checkType(value, key, valueType)){
    throw std::runtime_error(std::string("Key '" + key + "' is of wrong type"));
  }
}

// assert key is present and type is correct
void assertKeyAndType(const Json::Value& value, const std::string& key, const Json::ValueType& valueType)
{
  assertKey(value, key);
  assertType(value, key, valueType);
}

/// check key is present, return false if key is not found
bool checkKey(const Json::Value& value, const std::string& key)
{
  if (!value.isMember(key)){
    return false;
  }
  return true;
}

/// check type is correct if key is present, return false if type is not correct
bool checkType(const Json::Value& value, const std::string& key, const Json::ValueType& valueType)
{
  if (value.isMember(key)){
    if (!value[key].isConvertibleTo(valueType)){
      return false;
    }
    if (valueType != Json::nullValue){
      if (value[key].isNull()){
        return false;
      }
    }
  }
  return true;
}

/// check key is present and type is correct, return false if key not found or type is not correct
bool checkKeyAndType(const Json::Value& value, const std::string& key, const Json::ValueType& valueType)
{
  return (checkKey(value, key) && checkType(value, key, valueType));
}


} // openstudio
