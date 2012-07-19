MODULE := engines/wintermute
 
MODULE_OBJS := \
	Ad/AdActor.o \
	Ad/AdEntity.o \
	Ad/AdGame.o \
	Ad/AdInventory.o \
	Ad/AdInventoryBox.o \
	Ad/AdItem.o \
	Ad/AdLayer.o \
	Ad/AdNodeState.o \
	Ad/AdObject.o \
	Ad/AdPath.o \
	Ad/AdPathPoint.o \
	Ad/AdRegion.o \
	Ad/AdResponse.o \
	Ad/AdResponseBox.o \
	Ad/AdResponseContext.o \
	Ad/AdRotLevel.o \
	Ad/AdScaleLevel.o \
	Ad/AdScene.o \
	Ad/AdSceneNode.o \
	Ad/AdSceneState.o \
	Ad/AdSentence.o \
	Ad/AdSpriteSet.o \
	Ad/AdTalkDef.o \
	Ad/AdTalkHolder.o \
	Ad/AdTalkNode.o \
	Ad/AdWaypointGroup.o \
	Base/scriptables/ScEngine.o \
	Base/scriptables/ScScript.o \
	Base/scriptables/ScStack.o \
	Base/scriptables/ScValue.o \
	Base/scriptables/SXArray.o \
	Base/scriptables/SXDate.o \
	Base/scriptables/SXFile.o \
	Base/scriptables/SXMath.o \
	Base/scriptables/SxObject.o \
	Base/scriptables/SXMemBuffer.o \
	Base/scriptables/SXString.o \
	Base/file/BDiskFile.o \
	Base/file/BFile.o \
	Base/file/BSaveThumbFile.o \
	Base/file/BPkgFile.o \
	Base/font/BFontBitmap.o \
	Base/font/BFontTT.o \
	Base/font/BFont.o \
	Base/font/BFontStorage.o \
	Base/gfx/base_image.o \
	Base/gfx/base_renderer.o \
	Base/gfx/base_surface.o \
	Base/gfx/osystem/base_surface_osystem.o \
	Base/gfx/osystem/base_render_osystem.o \
	Base/particles/PartParticle.o \
	Base/particles/PartEmitter.o \
	Base/particles/PartForce.o \
	Base/BActiveRect.o \
	Base/BBase.o \
	Base/BDebugger.o \
	Base/BDynBuffer.o \
	Base/BFader.o \
	Base/BFileEntry.o \
	Base/BFileManager.o \
	Base/BGame.o \
	Base/BFrame.o \
	Base/BKeyboardState.o \
	Base/BNamedObject.o \
	Base/BObject.o \
	Base/BPackage.o \
	Base/BParser.o \
	Base/BPersistMgr.o \
	Base/BPoint.o \
	Base/BQuickMsg.o \
	Base/BRegion.o \
	Base/BRegistry.o \
	Base/BResources.o \
	Base/BSaveThumbHelper.o \
	Base/BScriptable.o \
	Base/BScriptHolder.o \
	Base/BSound.o \
	Base/BSoundBuffer.o \
	Base/BSoundMgr.o \
	Base/BSprite.o \
	Base/BStringTable.o \
	Base/BSubFrame.o \
	Base/BSurfaceStorage.o \
	Base/BTransitionMgr.o \
	Base/BViewport.o \
	detection.o \
	graphics/transparentSurface.o \
	graphics/tga.o \
	math/MathUtil.o \
	math/Matrix4.o \
	math/Vector2.o \
	PlatformSDL.o \
	Sys/SysClass.o \
	Sys/SysClassRegistry.o \
	Sys/SysInstance.o \
	tinyxml/tinyxml.o \
	tinyxml/tinystr.o \
	tinyxml/tinyxmlparser.o \
	tinyxml/tinyxmlerror.o \
	UI/UIButton.o \
	UI/UIEdit.o \
	UI/UIEntity.o \
	UI/UIObject.o \
	UI/UIText.o \
	UI/UITiledImage.o \
	UI/UIWindow.o \
	utils/ConvertUTF.o \
	utils/crc.o \
	utils/PathUtil.o \
	utils/StringUtil.o \
	utils/utils.o \
	video/VidPlayer.o \
	video/VidTheoraPlayer.o \
	video/decoders/theora_decoder.o \
	wintermute.o \
	persistent.o
 
MODULE_DIRS += \
	engines/wintermute
 
# This module can be built as a plugin
ifeq ($(ENABLE_WINTERMUTE), DYNAMIC_PLUGIN)
PLUGIN := 1
endif
 
# Include common rules 
include $(srcdir)/rules.mk
