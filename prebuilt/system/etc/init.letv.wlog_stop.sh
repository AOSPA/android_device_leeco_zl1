#!/system/bin/sh

LOG_TAG="letv-wlog"
LOG_NAME="${0}:"

logi ()
{
  /system/bin/log -t $LOG_TAG -p i "$LOG_NAME $@"
}

logi ""
logpath=$(cat /sdcard/wlan_logs/tmp_path)

# stop recording package log
pktlogconf -d cld
# stop recording wlan firmware and driver log
setprop ctl.stop cnss_diag

# relocate package log
cat /proc/ath_pktlog/cld > $logpath/data.dat
# relocate wlan firmware and driver log
mv /sdcard/wlan_logs/* $logpath

exit 0
