#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x8dacb15d, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x65e75cb6, __VMLINUX_SYMBOL_STR(__list_del_entry) },
	{ 0xb2cf9a27, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0xfef9bda2, __VMLINUX_SYMBOL_STR(kobject_del) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x63d4fba2, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x3c93d725, __VMLINUX_SYMBOL_STR(module_mutex) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "A5B173D57E03C06822D9964");
