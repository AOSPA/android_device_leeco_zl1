#!/system/bin/sh

LOG_TAG="letv-wlog"
LOG_NAME="${0}:"

logi ()
{
  /system/bin/log -t $LOG_TAG -p i "$LOG_NAME $@"
}

logi ""

if [ ! -d "/sdcard/wlan_logs" ]; then
  mkdir /sdcard/wlan_logs
else
  rm /sdcard/wlan_logs/*
fi

echo "$1" > /sdcard/wlan_logs/tmp_path

# start recording wlan firmware log and driver log
setprop ctl.start cnss_diag
# start recording package log
pktlogconf -s 10000000 -e -a cld

exit 0
