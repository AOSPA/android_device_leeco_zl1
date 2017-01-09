# Copyright (C) 2010 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

#
# This file is the build configuration for a full Android
# build for grouper hardware. This cleanly combines a set of
# device-specific aspects (drivers) with a device-agnostic
# product configuration (apps).
#

# Sample: This is where we'd set a backup provider if we had one
# $(call inherit-product, device/sample/products/backup_overlay.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)

# Get the prebuilt list of APNs
$(call inherit-product, vendor/omni/config/gsm.mk)

# Inherit from the common Open Source product configuration
$(call inherit-product, $(SRC_TARGET_DIR)/product/aosp_base_telephony.mk)

# must be before including omni part
TARGET_BOOTANIMATION_SIZE := 1080x720

# Inherit from our custom product configuration
$(call inherit-product, vendor/omni/config/common.mk)

# Inherit from hardware-specific part of the product configuration
$(call inherit-product, device/leeco/le_zl1/device.mk)

# SELinux
PRODUCT_PROPERTY_OVERRIDES += \
    ro.build.selinux=1

# Discard inherited values and use our own instead.
PRODUCT_NAME := omni_le_zl1
PRODUCT_DEVICE := le_zl1
PRODUCT_BRAND := LeEco
PRODUCT_MODEL := LEX720
PRODUCT_MANUFACTURER := LeMobile

PRODUCT_BUILD_PROP_OVERRIDES += \
    TARGET_DEVICE=le_zl1 \
    PRODUCT_NAME=ZL1_CN \
    BUILD_FINGERPRINT=LeEco/ZL1_CN/le_zl1:6.0.1/WAXCNFN5801811012S/letv11011204:user/release-keys \
    PRIVATE_BUILD_DESC="le_zl1-user 6.0.1 WAXCNFN5801811012S eng.letv.20161101.120034 release-keys"

#PRODUCT_SYSTEM_PROPERTY_BLACKLIST += ro.product.model

