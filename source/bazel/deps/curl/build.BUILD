# Description: curl is a tool for talking to web servers.

# This is BUILD file is derived from  https://github.com/tensorflow/tensorflow/blob/master/third_party/curl.BUILD

licenses(["notice"])  # MIT/X derivative license

exports_files(["COPYING"])

curl_copts = [
    "-Iexternal/curl/lib",
    "-D_GNU_SOURCE",
    "-DBUILDING_LIBCURL",
    "-DHAVE_CONFIG_H",
    "-DCURL_DISABLE_FTP",
    "-DCURL_DISABLE_NTLM",  # turning it off in configure is not enough
    "-DHAVE_LIBZ",
    "-DHAVE_ZLIB_H",
    "-DCURL_MAX_WRITE_SIZE=65536",
    "-Wno-everything",
]

cc_library(
    name = "curl",
    srcs = [
        "lib/amigaos.c",
        "lib/amigaos.h",
        "lib/arpa_telnet.h",
        "lib/asyn.h",
        "lib/asyn-ares.c",
        "lib/asyn-thread.c",
        "lib/base64.c",
        "lib/conncache.c",
        "lib/conncache.h",
        "lib/connect.c",
        "lib/connect.h",
        "lib/content_encoding.c",
        "lib/content_encoding.h",
        "lib/cookie.c",
        "lib/cookie.h",
        "lib/curl_addrinfo.c",
        "lib/curl_addrinfo.h",
        "lib/curl_base64.h",
        "lib/curl_config.h",
        "lib/curl_ctype.c",
        "lib/curl_ctype.h",
        "lib/curl_des.c",
        "lib/curl_des.h",
        "lib/curl_endian.c",
        "lib/curl_endian.h",
        "lib/curl_fnmatch.c",
        "lib/curl_fnmatch.h",
        "lib/curl_gethostname.c",
        "lib/curl_gethostname.h",
        "lib/curl_gssapi.c",
        "lib/curl_gssapi.h",
        "lib/curl_hmac.h",
        "lib/curl_ldap.h",
        "lib/curl_md4.h",
        "lib/curl_md5.h",
        "lib/curl_memory.h",
        "lib/curl_memrchr.c",
        "lib/curl_memrchr.h",
        "lib/curl_multibyte.c",
        "lib/curl_multibyte.h",
        "lib/curl_ntlm_core.c",
        "lib/curl_ntlm_core.h",
        "lib/curl_ntlm_wb.c",
        "lib/curl_ntlm_wb.h",
        "lib/curl_path.c",
        "lib/curl_path.h",
        "lib/curl_printf.h",
        "lib/curl_range.c",
        "lib/curl_range.h",
        "lib/curl_rtmp.c",
        "lib/curl_rtmp.h",
        "lib/curl_sasl.c",
        "lib/curl_sasl.h",
        "lib/curl_sec.h",
        "lib/curl_setup.h",
        "lib/curl_setup_once.h",
        "lib/curl_sha256.h",
        "lib/curl_sspi.c",
        "lib/curl_sspi.h",
        "lib/curl_threads.c",
        "lib/curl_threads.h",
        "lib/curlx.h",
        "lib/dict.c",
        "lib/dict.h",
        "lib/doh.c",
        "lib/doh.h",
        "lib/dotdot.c",
        "lib/dotdot.h",
        "lib/easy.c",
        "lib/easyif.h",
        "lib/escape.c",
        "lib/escape.h",
        "lib/file.c",
        "lib/file.h",
        "lib/fileinfo.c",
        "lib/fileinfo.h",
        "lib/formdata.c",
        "lib/formdata.h",
        "lib/ftp.c",
        "lib/ftp.h",
        "lib/ftplistparser.c",
        "lib/ftplistparser.h",
        "lib/getenv.c",
        "lib/getinfo.c",
        "lib/getinfo.h",
        "lib/gopher.c",
        "lib/gopher.h",
        "lib/hash.c",
        "lib/hash.h",
        "lib/hmac.c",
        "lib/hostasyn.c",
        "lib/hostcheck.c",
        "lib/hostcheck.h",
        "lib/hostip.c",
        "lib/hostip.h",
        "lib/hostip4.c",
        "lib/hostip6.c",
        "lib/hostsyn.c",
        "lib/http.c",
        "lib/http.h",
        "lib/http2.c",
        "lib/http2.h",
        "lib/http_chunks.c",
        "lib/http_chunks.h",
        "lib/http_digest.c",
        "lib/http_digest.h",
        "lib/http_negotiate.c",
        "lib/http_negotiate.h",
        "lib/http_ntlm.c",
        "lib/http_ntlm.h",
        "lib/http_proxy.c",
        "lib/http_proxy.h",
        "lib/idn_win32.c",
        "lib/if2ip.c",
        "lib/if2ip.h",
        "lib/imap.c",
        "lib/imap.h",
        "lib/inet_ntop.c",
        "lib/inet_ntop.h",
        "lib/inet_pton.c",
        "lib/inet_pton.h",
        "lib/krb5.c",
        "lib/ldap.c",
        "lib/llist.c",
        "lib/llist.h",
        "lib/md4.c",
        "lib/md5.c",
        "lib/memdebug.c",
        "lib/memdebug.h",
        "lib/mime.c",
        "lib/mime.h",
        "lib/mprintf.c",
        "lib/multi.c",
        "lib/multihandle.h",
        "lib/multiif.h",
        "lib/netrc.c",
        "lib/netrc.h",
        "lib/non-ascii.c",
        "lib/non-ascii.h",
        "lib/nonblock.c",
        "lib/nonblock.h",
        "lib/openldap.c",
        "lib/parsedate.c",
        "lib/parsedate.h",
        "lib/pingpong.c",
        "lib/pingpong.h",
        "lib/pipeline.c",
        "lib/pipeline.h",
        "lib/pop3.c",
        "lib/pop3.h",
        "lib/progress.c",
        "lib/progress.h",
        "lib/psl.c",
        "lib/psl.h",
        "lib/rand.c",
        "lib/rand.h",
        "lib/rtsp.c",
        "lib/rtsp.h",
        "lib/security.c",
        "lib/select.c",
        "lib/select.h",
        "lib/sendf.c",
        "lib/sendf.h",
        "lib/setopt.c",
        "lib/setopt.h",
        "lib/setup-vms.h",
        "lib/sha256.c",
        "lib/share.c",
        "lib/share.h",
        "lib/sigpipe.h",
        "lib/slist.c",
        "lib/slist.h",
        "lib/smb.c",
        "lib/smb.h",
        "lib/smtp.c",
        "lib/smtp.h",
        "lib/sockaddr.h",
        "lib/socks.c",
        "lib/socks.h",
        "lib/socks_gssapi.c",
        "lib/socks_sspi.c",
        "lib/speedcheck.c",
        "lib/speedcheck.h",
        "lib/splay.c",
        "lib/splay.h",
        "lib/ssh.c",
        "lib/ssh.h",
        "lib/ssh-libssh.c",
        "lib/strcase.c",
        "lib/strcase.h",
        "lib/strdup.c",
        "lib/strdup.h",
        "lib/strerror.c",
        "lib/strerror.h",
        "lib/strtok.c",
        "lib/strtok.h",
        "lib/strtoofft.c",
        "lib/strtoofft.h",
        "lib/system_win32.c",
        "lib/system_win32.h",
        "lib/telnet.c",
        "lib/telnet.h",
        "lib/tftp.c",
        "lib/tftp.h",
        "lib/timeval.c",
        "lib/timeval.h",
        "lib/transfer.c",
        "lib/transfer.h",
        "lib/url.c",
        "lib/url.h",
        "lib/urlapi.c",
        "lib/urlapi-int.h",
        "lib/urldata.h",
        "lib/vauth/cleartext.c",
        "lib/vauth/cram.c",
        "lib/vauth/digest.c",
        "lib/vauth/digest.h",
        "lib/vauth/digest_sspi.c",
        "lib/vauth/krb5_gssapi.c",
        "lib/vauth/krb5_sspi.c",
        "lib/vauth/ntlm.c",
        "lib/vauth/ntlm.h",
        "lib/vauth/ntlm_sspi.c",
        "lib/vauth/oauth2.c",
        "lib/vauth/spnego_gssapi.c",
        "lib/vauth/spnego_sspi.c",
        "lib/vauth/vauth.c",
        "lib/vauth/vauth.h",
        "lib/version.c",
        #"lib/vtls/axtls.c",
        #"lib/vtls/axtls.h",
        "lib/vtls/cyassl.c",
        "lib/vtls/cyassl.h",
        "lib/vtls/darwinssl.c",
        "lib/vtls/darwinssl.h",
        "lib/vtls/gskit.c",
        "lib/vtls/gskit.h",
        "lib/vtls/gtls.c",
        "lib/vtls/gtls.h",
        "lib/vtls/mbedtls.c",
        "lib/vtls/mbedtls.h",
        "lib/vtls/mesalink.c",
        "lib/vtls/mesalink.h",
        "lib/vtls/nss.c",
        "lib/vtls/nssg.h",
        "lib/vtls/openssl.c",
        "lib/vtls/openssl.h",
        "lib/vtls/polarssl.c",
        "lib/vtls/polarssl.h",
        "lib/vtls/polarssl_threadlock.c",
        "lib/vtls/polarssl_threadlock.h",
        "lib/vtls/schannel.c",
        "lib/vtls/schannel.h",
        "lib/vtls/schannel_verify.c",
        "lib/vtls/vtls.c",
        "lib/vtls/vtls.h",
        "lib/warnless.c",
        "lib/warnless.h",
        "lib/wildcard.c",
        "lib/wildcard.h",
        "lib/x509asn1.c",
        "lib/x509asn1.h",
    ],
    hdrs = [
        "include/curl/curl.h",
        "include/curl/curlver.h",
        "include/curl/easy.h",
        "include/curl/mprintf.h",
        "include/curl/multi.h",
        "include/curl/stdcheaders.h",
        "include/curl/system.h",
        "include/curl/typecheck-gcc.h",
        "include/curl/urlapi.h",
    ],
    copts = curl_copts,
    defines = ["CURL_STATICLIB"],
    includes = ["include"],
    #linkopts = ["-lrt"],
    visibility = ["//visibility:public"],
    deps = [
        "@net_zlib_zlib//:zlib",
        "@openssl//:crypto",
        "@openssl//:ssl",
    ],
)

# All files from curl/src/Makfile.inc
curl_cfiles = [
    "src/slist_wc.c",
    "src/tool_cb_dbg.c",
    "src/tool_cb_hdr.c",
    "src/tool_cb_prg.c",
    "src/tool_cb_rea.c",
    "src/tool_cb_see.c",
    "src/tool_cb_wrt.c",
    "src/tool_cfgable.c",
    "src/tool_convert.c",
    "src/tool_dirhie.c",
    "src/tool_doswin.c",
    "src/tool_easysrc.c",
    "src/tool_filetime.c",
    "src/tool_formparse.c",
    "src/tool_getparam.c",
    "src/tool_getpass.c",
    "src/tool_help.c",
    "src/tool_helpers.c",
    "src/tool_homedir.c",
    "src/tool_hugehelp.c",
    "src/tool_libinfo.c",
    "src/tool_main.c",
    "src/tool_metalink.c",
    "src/tool_msgs.c",
    "src/tool_operate.c",
    "src/tool_operhlp.c",
    "src/tool_panykey.c",
    "src/tool_paramhlp.c",
    "src/tool_parsecfg.c",
    "src/tool_setopt.c",
    "src/tool_sleep.c",
    "src/tool_strdup.c",
    "src/tool_urlglob.c",
    "src/tool_util.c",
    "src/tool_vms.c",
    "src/tool_writeout.c",
    "src/tool_xattr.c",
    "src/tool_binmode.c",
    "src/tool_bname.c",
]

curl_hfiles = [
    "src/slist_wc.h",
    "src/tool_binmode.h",
    "src/tool_bname.h",
    "src/tool_cb_dbg.h",
    "src/tool_cb_hdr.h",
    "src/tool_cb_prg.h",
    "src/tool_cb_rea.h",
    "src/tool_cb_see.h",
    "src/tool_cb_wrt.h",
    "src/tool_cfgable.h",
    "src/tool_convert.h",
    "src/tool_dirhie.h",
    "src/tool_doswin.h",
    "src/tool_easysrc.h",
    "src/tool_filetime.h",
    "src/tool_formparse.h",
    "src/tool_getparam.h",
    "src/tool_getpass.h",
    "src/tool_help.h",
    "src/tool_helpers.h",
    "src/tool_homedir.h",
    "src/tool_hugehelp.h",
    "src/tool_libinfo.h",
    "src/tool_main.h",
    "src/tool_metalink.h",
    "src/tool_msgs.h",
    "src/tool_operate.h",
    "src/tool_operhlp.h",
    "src/tool_panykey.h",
    "src/tool_paramhlp.h",
    "src/tool_parsecfg.h",
    "src/tool_sdecls.h",
    "src/tool_setopt.h",
    "src/tool_setup.h",
    "src/tool_sleep.h",
    "src/tool_strdup.h",
    "src/tool_urlglob.h",
    "src/tool_util.h",
    "src/tool_version.h",
    "src/tool_vms.h",
    "src/tool_writeout.h",
    "src/tool_xattr.h",
]

cc_binary(
    name = "cli",
    srcs = curl_cfiles + curl_hfiles,
    copts = curl_copts,
    visibility = ["//visibility:public"],
    deps = [":curl"],
)
