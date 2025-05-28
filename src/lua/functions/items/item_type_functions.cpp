////////////////////////////////////////////////////////////////////////
// Crystal Server - an opensource roleplaying game
////////////////////////////////////////////////////////////////////////
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
////////////////////////////////////////////////////////////////////////

#include "lua/functions/items/item_type_functions.hpp"

#include "items/item.hpp"
#include "items/items.hpp"
#include "lua/functions/lua_functions_loader.hpp"

void ItemTypeFunctions::init(lua_State* L) {
	Lua::registerClass(L, "ItemType", "", ItemTypeFunctions::luaItemTypeCreate);
	Lua::registerMetaMethod(L, "ItemType", "__eq", Lua::luaUserdataCompare);

	Lua::registerMethod(L, "ItemType", "isCorpse", ItemTypeFunctions::luaItemTypeIsCorpse);
	Lua::registerMethod(L, "ItemType", "isDoor", ItemTypeFunctions::luaItemTypeIsDoor);
	Lua::registerMethod(L, "ItemType", "isContainer", ItemTypeFunctions::luaItemTypeIsContainer);
	Lua::registerMethod(L, "ItemType", "isFluidContainer", ItemTypeFunctions::luaItemTypeIsFluidContainer);
	Lua::registerMethod(L, "ItemType", "isMovable", ItemTypeFunctions::luaItemTypeIsMovable);
	Lua::registerMethod(L, "ItemType", "isRune", ItemTypeFunctions::luaItemTypeIsRune);
	Lua::registerMethod(L, "ItemType", "isStackable", ItemTypeFunctions::luaItemTypeIsStackable);
	Lua::registerMethod(L, "ItemType", "isStowable", ItemTypeFunctions::luaItemTypeIsStowable);
	Lua::registerMethod(L, "ItemType", "isReadable", ItemTypeFunctions::luaItemTypeIsReadable);
	Lua::registerMethod(L, "ItemType", "isWritable", ItemTypeFunctions::luaItemTypeIsWritable);
	Lua::registerMethod(L, "ItemType", "isBlocking", ItemTypeFunctions::luaItemTypeIsBlocking);
	Lua::registerMethod(L, "ItemType", "isGroundTile", ItemTypeFunctions::luaItemTypeIsGroundTile);
	Lua::registerMethod(L, "ItemType", "isMagicField", ItemTypeFunctions::luaItemTypeIsMagicField);
	Lua::registerMethod(L, "ItemType", "isMultiUse", ItemTypeFunctions::luaItemTypeIsMultiUse);
	Lua::registerMethod(L, "ItemType", "isPickupable", ItemTypeFunctions::luaItemTypeIsPickupable);
	Lua::registerMethod(L, "ItemType", "isKey", ItemTypeFunctions::luaItemTypeIsKey);
	Lua::registerMethod(L, "ItemType", "isQuiver", ItemTypeFunctions::luaItemTypeIsQuiver);

	Lua::registerMethod(L, "ItemType", "isPodium", ItemTypeFunctions::luaItemTypeIsPodium);
	Lua::registerMethod(L, "ItemType", "getType", ItemTypeFunctions::luaItemTypeGetType);
	Lua::registerMethod(L, "ItemType", "getGroup", ItemTypeFunctions::luaItemTypeGetGroup);
	Lua::registerMethod(L, "ItemType", "getId", ItemTypeFunctions::luaItemTypeGetId);
	Lua::registerMethod(L, "ItemType", "getName", ItemTypeFunctions::luaItemTypeGetName);
	Lua::registerMethod(L, "ItemType", "getPluralName", ItemTypeFunctions::luaItemTypeGetPluralName);
	Lua::registerMethod(L, "ItemType", "getArticle", ItemTypeFunctions::luaItemTypeGetArticle);
	Lua::registerMethod(L, "ItemType", "getDescription", ItemTypeFunctions::luaItemTypeGetDescription);
	Lua::registerMethod(L, "ItemType", "getSlotPosition", ItemTypeFunctions::luaItemTypeGetSlotPosition);
	Lua::registerMethod(L, "ItemType", "getRotateId", ItemTypeFunctions::luaItemTypeGetRotateId);
	Lua::registerMethod(L, "ItemType", "getWareId", ItemTypeFunctions::luaItemTypeGetWareId);

	Lua::registerMethod(L, "ItemType", "getCharges", ItemTypeFunctions::luaItemTypeGetCharges);
	Lua::registerMethod(L, "ItemType", "getFluidSource", ItemTypeFunctions::luaItemTypeGetFluidSource);
	Lua::registerMethod(L, "ItemType", "getCapacity", ItemTypeFunctions::luaItemTypeGetCapacity);
	Lua::registerMethod(L, "ItemType", "getWeight", ItemTypeFunctions::luaItemTypeGetWeight);
	Lua::registerMethod(L, "ItemType", "getStackSize", ItemTypeFunctions::luaItemTypeGetStackSize);

	Lua::registerMethod(L, "ItemType", "getHitChance", ItemTypeFunctions::luaItemTypeGetHitChance);
	Lua::registerMethod(L, "ItemType", "getShootRange", ItemTypeFunctions::luaItemTypeGetShootRange);

	Lua::registerMethod(L, "ItemType", "getAttack", ItemTypeFunctions::luaItemTypeGetAttack);
	Lua::registerMethod(L, "ItemType", "getDefense", ItemTypeFunctions::luaItemTypeGetDefense);
	Lua::registerMethod(L, "ItemType", "getExtraDefense", ItemTypeFunctions::luaItemTypeGetExtraDefense);
	Lua::registerMethod(L, "ItemType", "getImbuementSlot", ItemTypeFunctions::luaItemTypeGetImbuementSlot);
	Lua::registerMethod(L, "ItemType", "getArmor", ItemTypeFunctions::luaItemTypeGetArmor);
	Lua::registerMethod(L, "ItemType", "getWeaponType", ItemTypeFunctions::luaItemTypeGetWeaponType);

	Lua::registerMethod(L, "ItemType", "getElementType", ItemTypeFunctions::luaItemTypeGetElementType);
	Lua::registerMethod(L, "ItemType", "getElementDamage", ItemTypeFunctions::luaItemTypeGetElementDamage);

	Lua::registerMethod(L, "ItemType", "getTransformEquipId", ItemTypeFunctions::luaItemTypeGetTransformEquipId);
	Lua::registerMethod(L, "ItemType", "getTransformDeEquipId", ItemTypeFunctions::luaItemTypeGetTransformDeEquipId);
	Lua::registerMethod(L, "ItemType", "getDestroyId", ItemTypeFunctions::luaItemTypeGetDestroyId);
	Lua::registerMethod(L, "ItemType", "getDecayId", ItemTypeFunctions::luaItemTypeGetDecayId);
	Lua::registerMethod(L, "ItemType", "getRequiredLevel", ItemTypeFunctions::luaItemTypeGetRequiredLevel);
	Lua::registerMethod(L, "ItemType", "getAmmoType", ItemTypeFunctions::luaItemTypeGetAmmoType);
	Lua::registerMethod(L, "ItemType", "getCorpseType", ItemTypeFunctions::luaItemTypeGetCorpseType);
	Lua::registerMethod(L, "ItemType", "getClassification", ItemTypeFunctions::luaItemTypeGetClassification);

	Lua::registerMethod(L, "ItemType", "getDecayTime", ItemTypeFunctions::luaItemTypeGetDecayTime);
	Lua::registerMethod(L, "ItemType", "getShowDuration", ItemTypeFunctions::luaItemTypeGetShowDuration);
	Lua::registerMethod(L, "ItemType", "getWrapableTo", ItemTypeFunctions::luaItemTypeGetWrapableTo);
	Lua::registerMethod(L, "ItemType", "getSpeed", ItemTypeFunctions::luaItemTypeGetSpeed);
	Lua::registerMethod(L, "ItemType", "getBaseSpeed", ItemTypeFunctions::luaItemTypeGetBaseSpeed);
	Lua::registerMethod(L, "ItemType", "getVocationString", ItemTypeFunctions::luaItemTypeGetVocationString);

	Lua::registerMethod(L, "ItemType", "getElementalBond", ItemTypeFunctions::luaItemTypeGetElementalBond);
	Lua::registerMethod(L, "ItemType", "getMantra", ItemTypeFunctions::luaItemTypeGetMantra);

	Lua::registerMethod(L, "ItemType", "hasSubType", ItemTypeFunctions::luaItemTypeHasSubType);
	Lua::registerMethod(L, "ItemType", "getAbilities", ItemTypeFunctions::luaItemTypeGetAbilities);

	Lua::registerMethod(L, "ItemType", "isWrapKit", ItemTypeFunctions::luaItemTypeIsWrapKit);
	Lua::registerMethod(L, "ItemType", "isSpellBook", ItemTypeFunctions::luaItemTypeIsSpellBook);

	ItemClassificationFunctions::init(L);
}

int ItemTypeFunctions::luaItemTypeCreate(lua_State* L) {
	// ItemType(id or name)
	uint32_t id;
	if (Lua::isNumber(L, 2)) {
		id = Lua::getNumber<uint32_t>(L, 2);
	} else {
		id = Item::items.getItemIdByName(Lua::getString(L, 2));
	}

	const ItemType &itemType = Item::items[id];
	Lua::pushUserdata<const ItemType>(L, &itemType);
	Lua::setMetatable(L, -1, "ItemType");
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsCorpse(lua_State* L) {
	// itemType:isCorpse()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushBoolean(L, itemType->isCorpse);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsDoor(lua_State* L) {
	// itemType:isDoor()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushBoolean(L, itemType->isDoor());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsContainer(lua_State* L) {
	// itemType:isContainer()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushBoolean(L, itemType->isContainer());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsFluidContainer(lua_State* L) {
	// itemType:isFluidContainer()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushBoolean(L, itemType->isFluidContainer());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsMovable(lua_State* L) {
	// itemType:isMovable()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushBoolean(L, itemType->movable);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsRune(lua_State* L) {
	// itemType:isRune()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushBoolean(L, itemType->isRune());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsStackable(lua_State* L) {
	// itemType:isStackable()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushBoolean(L, itemType->stackable);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsStowable(lua_State* L) {
	// itemType:isStowable()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushBoolean(L, itemType->stackable && itemType->wareId > 0);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsReadable(lua_State* L) {
	// itemType:isReadable()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushBoolean(L, itemType->canReadText);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsWritable(lua_State* L) {
	// itemType:isWritable()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushBoolean(L, itemType->canWriteText);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsBlocking(lua_State* L) {
	// itemType:isBlocking()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushBoolean(L, itemType->blockProjectile || itemType->blockSolid);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsGroundTile(lua_State* L) {
	// itemType:isGroundTile()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushBoolean(L, itemType->isGroundTile());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsMagicField(lua_State* L) {
	// itemType:isMagicField()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushBoolean(L, itemType->isMagicField());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsMultiUse(lua_State* L) {
	// itemType:isMultiUse()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushBoolean(L, itemType->isMultiUse());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsPickupable(lua_State* L) {
	// itemType:isPickupable()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushBoolean(L, itemType->isPickupable());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsKey(lua_State* L) {
	// itemType:isKey()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushBoolean(L, itemType->isKey());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsQuiver(lua_State* L) {
	// itemType:isQuiver()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushBoolean(L, itemType->isQuiver());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsPodium(lua_State* L) {
	// itemType:isPodium()
	const ItemType* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushBoolean(L, itemType->isPodium);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetType(lua_State* L) {
	// itemType:getType()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->type);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetGroup(lua_State* L) {
	// itemType:getGroup()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->group);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetId(lua_State* L) {
	// itemType:getId()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->id);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetName(lua_State* L) {
	// itemType:getName()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushString(L, itemType->name);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetPluralName(lua_State* L) {
	// itemType:getPluralName()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushString(L, itemType->getPluralName());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetArticle(lua_State* L) {
	// itemType:getArticle()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushString(L, itemType->article);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetDescription(lua_State* L) {
	// itemType:getDescription([count])
	const auto &itemType = Lua::getUserdata<ItemType>(L, 1);
	if (itemType) {
		const auto count = Lua::getNumber<uint16_t>(L, 2, -1);
		const auto description = Item::getDescription(*itemType, 1, nullptr, count);
		Lua::pushString(L, description);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetSlotPosition(lua_State* L) {
	// itemType:getSlotPosition()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->slotPosition);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetCharges(lua_State* L) {
	// itemType:getCharges()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->charges);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetFluidSource(lua_State* L) {
	// itemType:getFluidSource()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->fluidSource);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetCapacity(lua_State* L) {
	// itemType:getCapacity()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->maxItems);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetWeight(lua_State* L) {
	// itemType:getWeight([count = 1])
	const auto count = Lua::getNumber<uint16_t>(L, 2, 1);

	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (!itemType) {
		lua_pushnil(L);
		return 1;
	}

	const uint64_t weight = static_cast<uint64_t>(itemType->weight) * std::max<int32_t>(1, count);
	lua_pushnumber(L, weight);
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetStackSize(lua_State* L) {
	// itemType:getStackSize()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (!itemType) {
		lua_pushnil(L);
		return 1;
	}

	const auto stackSize = static_cast<uint64_t>(itemType->stackSize);
	lua_pushnumber(L, stackSize);
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetHitChance(lua_State* L) {
	// itemType:getHitChance()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->hitChance);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetShootRange(lua_State* L) {
	// itemType:getShootRange()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->shootRange);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetAttack(lua_State* L) {
	// itemType:getAttack()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->attack);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetDefense(lua_State* L) {
	// itemType:getDefense()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->defense);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetExtraDefense(lua_State* L) {
	// itemType:getExtraDefense()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->extraDefense);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetImbuementSlot(lua_State* L) {
	// itemType:getImbuementSlot()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->imbuementSlot);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetArmor(lua_State* L) {
	// itemType:getArmor()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->armor);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetWeaponType(lua_State* L) {
	// itemType:getWeaponType()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->weaponType);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetAmmoType(lua_State* L) {
	// itemType:getAmmoType()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->ammoType);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetCorpseType(lua_State* L) {
	// itemType:getCorpseType()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->corpseType);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetClassification(lua_State* L) {
	// itemType:getClassification()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->upgradeClassification);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetElementType(lua_State* L) {
	// itemType:getElementType()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (!itemType) {
		lua_pushnil(L);
		return 1;
	}

	auto &abilities = itemType->abilities;
	if (abilities) {
		lua_pushnumber(L, abilities->elementType);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetElementDamage(lua_State* L) {
	// itemType:getElementDamage()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (!itemType) {
		lua_pushnil(L);
		return 1;
	}

	auto &abilities = itemType->abilities;
	if (abilities) {
		lua_pushnumber(L, abilities->elementDamage);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetTransformEquipId(lua_State* L) {
	// itemType:getTransformEquipId()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->transformEquipTo);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetTransformDeEquipId(lua_State* L) {
	// itemType:getTransformDeEquipId()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->transformDeEquipTo);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetDestroyId(lua_State* L) {
	// itemType:getDestroyId()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->destroyTo);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetDecayId(lua_State* L) {
	// itemType:getDecayId()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->decayTo);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetRequiredLevel(lua_State* L) {
	// itemType:getRequiredLevel()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->minReqLevel);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetSpeed(lua_State* L) {
	// itemType:getSpeed()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (!itemType) {
		lua_pushnil(L);
		return 1;
	}

	auto &abilities = itemType->abilities;
	if (abilities) {
		lua_pushnumber(L, abilities->speed);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetBaseSpeed(lua_State* L) {
	// itemType:getBaseSpeed()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->speed);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetDecayTime(lua_State* L) {
	// itemType:getDecayTime()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->decayTime);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetShowDuration(lua_State* L) {
	// itemType:getShowDuration()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushboolean(L, itemType->showDuration);
	} else {
		lua_pushnil(L);
	}
	return 1;
}
int ItemTypeFunctions::luaItemTypeGetWrapableTo(lua_State* L) {
	// itemType:getWrapableTo()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->wrapableTo);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeHasSubType(lua_State* L) {
	// itemType:hasSubType()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushBoolean(L, itemType->hasSubType());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetAbilities(lua_State* L) {
	// itemType:getAbilities()
	auto* itemType = const_cast<ItemType*>(Lua::getUserdata<const ItemType>(L, 1));
	if (itemType) {
		Abilities &abilities = itemType->getAbilities();

		lua_createtable(L, 6, 21);
		Lua::setField(L, "healthGain", abilities.healthGain);
		Lua::setField(L, "healthTicks", abilities.healthTicks);
		Lua::setField(L, "manaGain", abilities.manaGain);
		Lua::setField(L, "manaTicks", abilities.manaTicks);
		Lua::setField(L, "speed", abilities.speed);
		Lua::setField(L, "elementDamage", abilities.elementDamage);
		Lua::setField(L, "elementType", abilities.elementType);
		Lua::setField(L, "magicShieldCapacityPercent", abilities.magicShieldCapacityPercent);
		Lua::setField(L, "magicShieldCapacityFlat", abilities.magicShieldCapacityFlat);
		Lua::setField(L, "cleavePercent", abilities.cleavePercent);

		lua_pushboolean(L, abilities.manaShield);
		lua_setfield(L, -2, "manaShield");
		lua_pushboolean(L, abilities.invisible);
		lua_setfield(L, -2, "invisible");
		lua_pushboolean(L, abilities.regeneration);
		lua_setfield(L, -2, "regeneration");

		// conditionImmunities
		lua_createtable(L, abilities.conditionImmunities.size(), 0);
		for (size_t i = 0; i < abilities.conditionImmunities.size(); ++i) {
			lua_pushnumber(L, static_cast<int>(abilities.conditionImmunities[i]));
			lua_rawseti(L, -2, i + 1);
		}
		lua_setfield(L, -2, "conditionImmunities");

		// conditionSuppressions
		lua_createtable(L, abilities.conditionSuppressions.size(), 0);
		for (size_t i = 0; i < abilities.conditionSuppressions.size(); ++i) {
			lua_pushnumber(L, static_cast<int>(abilities.conditionSuppressions[i]));
			lua_rawseti(L, -2, i + 1);
		}
		lua_setfield(L, -2, "conditionSuppressions");

		// Stats
		lua_createtable(L, 0, STAT_LAST + 1);
		for (int32_t i = STAT_FIRST; i <= STAT_LAST; i++) {
			lua_pushnumber(L, abilities.stats[i]);
			lua_rawseti(L, -2, i + 1);
		}
		lua_setfield(L, -2, "stats");

		// Stats percent
		lua_createtable(L, 0, STAT_LAST + 1);
		for (int32_t i = STAT_FIRST; i <= STAT_LAST; i++) {
			lua_pushnumber(L, abilities.statsPercent[i]);
			lua_rawseti(L, -2, i + 1);
		}
		lua_setfield(L, -2, "statsPercent");

		// Skills
		lua_createtable(L, 0, SKILL_LAST + 1);
		for (int32_t i = SKILL_FIRST; i <= SKILL_LAST; i++) {
			lua_pushnumber(L, abilities.skills[i]);
			lua_rawseti(L, -2, i + 1);
		}
		lua_setfield(L, -2, "skills");

		// specializedMagicLevel
		lua_createtable(L, 0, COMBAT_COUNT);
		for (int32_t i = 0; i < COMBAT_COUNT; i++) {
			lua_pushnumber(L, abilities.specializedMagicLevel[i]);
			lua_rawseti(L, -2, i + 1);
		}
		lua_setfield(L, -2, "specializedMagicLevel");

		// Field absorb percent
		lua_createtable(L, 0, COMBAT_COUNT);
		for (int32_t i = 0; i < COMBAT_COUNT; i++) {
			lua_pushnumber(L, abilities.fieldAbsorbPercent[i]);
			lua_rawseti(L, -2, i + 1);
		}
		lua_setfield(L, -2, "fieldAbsorbPercent");

		// Absorb percent
		lua_createtable(L, 0, COMBAT_COUNT);
		for (int32_t i = 0; i < COMBAT_COUNT; i++) {
			lua_pushnumber(L, abilities.absorbPercent[i]);
			lua_rawseti(L, -2, i + 1);
		}
		lua_setfield(L, -2, "absorbPercent");

		//// Reflect
		// Reflect Flat (100% chance)
		lua_createtable(L, COMBAT_COUNT, 0);
		for (int32_t i = 0; i < COMBAT_COUNT; i++) {
			lua_pushnumber(L, abilities.reflectFlat[i]);
			lua_rawseti(L, -2, i + 1);
		}
		lua_setfield(L, -2, "reflectFlat");

		// Reflect percent
		lua_createtable(L, 0, COMBAT_COUNT);
		for (int32_t i = 0; i < COMBAT_COUNT; i++) {
			lua_pushnumber(L, abilities.reflectPercent[i]);
			lua_rawseti(L, -2, i + 1);
		}
		lua_setfield(L, -2, "reflectPercent");
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetVocationString(lua_State* L) {
	// itemType:getVocationString()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		Lua::pushString(L, itemType->vocationString);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetRotateId(lua_State* L) {
	// itemType:getRotateId()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType && itemType->rotatable) {
		lua_pushnumber(L, itemType->rotateTo);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetWareId(lua_State* L) {
	// itemType:getWareId()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->wareId);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsWrapKit(lua_State* L) {
	// itemType:isWrapKit()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->isWrapKit);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeIsSpellBook(lua_State* L) {
	// itemType:isSpellbook()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->spellbook);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetElementalBond(lua_State* L) {
	// itemType:getElementalBond()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (!itemType) {
		lua_pushnil(L);
		return 1;
	}

	if (!itemType->elementalBond.empty()) {
		lua_pushstring(L, itemType->elementalBond.c_str());
	} else {
		lua_pushstring(L, "physical");
	}
	return 1;
}

int ItemTypeFunctions::luaItemTypeGetMantra(lua_State* L) {
	// itemType:getMantra()
	const auto* itemType = Lua::getUserdata<const ItemType>(L, 1);
	if (itemType) {
		lua_pushnumber(L, itemType->mantra);
	} else {
		lua_pushnil(L);
	}
	return 1;
}
