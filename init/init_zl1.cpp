/*
 * Copyright (c) 2016-2017 - The Paranoid Android Project
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following
 *   disclaimer in the documentation and/or other materials provided
 *   with the distribution.
 * Neither the name of The Linux Foundation nor the names of its
 *   contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "init_msm.h"

#define DEVINFO_FILE "/dev/block/bootdevice/by-name/devinfo"

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type) {
    char device[PROP_VALUE_MAX];
    int chinese = 1;

    if (read_file2(DEVINFO_FILE, device, sizeof(device)))
    {
        if (!strncmp(device, "le_zl1_oversea", 14)) {
            chinese = 0;
        }
    }

    if (chinese)
    {
        // Set the main properties for the Chinese variant.
        property_set("persist.multisim.config", "dsds");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.telephony.default_network", "22,22");
        property_set("ro.product.model", "LEX720");
    } else {
        // Set the main properties for the American variant.
        property_set("persist.multisim.config", "NA");
        property_set("persist.radio.multisim.config", "NA");
        property_set("ro.telephony.default_network", "9");
        property_set("ro.product.model", "LEX727");
    }

    // Set the certified firgerprint from US variant.
    //property_set("ro.product.name", "ZL1_NA");
    //property_set("ro.product.customize", "oversea");
    //property_set("ro.build.id", "WEXNAOP5802012101S");
    property_set("ro.build.fingerprint", "LeEco/ZL1_NA/le_zl1:6.0.1/WEXNAOP5802012101S/letv12100148:user/release-keys");
    property_set("ro.build.description", "le_zl1-user 6.0.1 WEXNAOP5802012101S eng.letv.20161210.014420 release-keys");
    // Set the expected 'le_zl1' properties used in our blobs.
    property_set("ro.config.product", "le_zl1");
    property_set("ro.build.product", "le_zl1");
    //property_set("ro.product.device", "le_zl1");
}
