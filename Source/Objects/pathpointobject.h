//-----------------------------------------------------------------------------
//           Name: pathpointobject.h
//      Developer: Wolfire Games LLC
//    Description: 
//        License: Read below
//-----------------------------------------------------------------------------
//
//   Copyright 2022 Wolfire Games LLC
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//
//-----------------------------------------------------------------------------
#pragma once

#include <Objects/object.h>

#include <vector>
#include <string>
#include <list>

//-----------------------------------------------------------------------------
// Class Definition
//-----------------------------------------------------------------------------

class PathPointObject: public Object
{
public:
    virtual EntityType GetType() const { return _path_point_object; }
    std::vector<int> connection_ids;

    PathPointObject();
    
    virtual bool ConnectTo(Object& other, bool checking_other = false);
    virtual bool AcceptConnectionsFrom(ConnectionType type, Object& object);
    virtual bool Disconnect( Object& other, bool checking_other = false );
    virtual void GetConnectionIDs(std::vector<int>* cons);

    int GetModelID();
    virtual void NotifyDeleted( Object* o);
    void GetDesc(EntityDescription &desc) const;

    virtual bool SetFromDesc( const EntityDescription& desc );
    static void RegisterToScript(ASContext* as_context);
    virtual void Draw();
    virtual bool Initialize();

    virtual void RemapReferences(std::map<int,int> id_map);

};
