
bufbomb:     file format elf32-i386


Disassembly of section .init:

080487d8 <_init>:
 80487d8:	53                   	push   %ebx
 80487d9:	83 ec 08             	sub    $0x8,%esp
 80487dc:	e8 bf 02 00 00       	call   8048aa0 <__x86.get_pc_thunk.bx>
 80487e1:	81 c3 1f 48 00 00    	add    $0x481f,%ebx
 80487e7:	8b 83 fc ff ff ff    	mov    -0x4(%ebx),%eax
 80487ed:	85 c0                	test   %eax,%eax
 80487ef:	74 05                	je     80487f6 <_init+0x1e>
 80487f1:	e8 6a 02 00 00       	call   8048a60 <calloc@plt+0x10>
 80487f6:	83 c4 08             	add    $0x8,%esp
 80487f9:	5b                   	pop    %ebx
 80487fa:	c3                   	ret    

Disassembly of section .plt:

08048800 <strcmp@plt-0x10>:
 8048800:	ff 35 04 d0 04 08    	pushl  0x804d004
 8048806:	ff 25 08 d0 04 08    	jmp    *0x804d008
 804880c:	00 00                	add    %al,(%eax)
	...

08048810 <strcmp@plt>:
 8048810:	ff 25 0c d0 04 08    	jmp    *0x804d00c
 8048816:	68 00 00 00 00       	push   $0x0
 804881b:	e9 e0 ff ff ff       	jmp    8048800 <_init+0x28>

08048820 <read@plt>:
 8048820:	ff 25 10 d0 04 08    	jmp    *0x804d010
 8048826:	68 08 00 00 00       	push   $0x8
 804882b:	e9 d0 ff ff ff       	jmp    8048800 <_init+0x28>

08048830 <srandom@plt>:
 8048830:	ff 25 14 d0 04 08    	jmp    *0x804d014
 8048836:	68 10 00 00 00       	push   $0x10
 804883b:	e9 c0 ff ff ff       	jmp    8048800 <_init+0x28>

08048840 <printf@plt>:
 8048840:	ff 25 18 d0 04 08    	jmp    *0x804d018
 8048846:	68 18 00 00 00       	push   $0x18
 804884b:	e9 b0 ff ff ff       	jmp    8048800 <_init+0x28>

08048850 <strdup@plt>:
 8048850:	ff 25 1c d0 04 08    	jmp    *0x804d01c
 8048856:	68 20 00 00 00       	push   $0x20
 804885b:	e9 a0 ff ff ff       	jmp    8048800 <_init+0x28>

08048860 <memcpy@plt>:
 8048860:	ff 25 20 d0 04 08    	jmp    *0x804d020
 8048866:	68 28 00 00 00       	push   $0x28
 804886b:	e9 90 ff ff ff       	jmp    8048800 <_init+0x28>

08048870 <bzero@plt>:
 8048870:	ff 25 24 d0 04 08    	jmp    *0x804d024
 8048876:	68 30 00 00 00       	push   $0x30
 804887b:	e9 80 ff ff ff       	jmp    8048800 <_init+0x28>

08048880 <signal@plt>:
 8048880:	ff 25 28 d0 04 08    	jmp    *0x804d028
 8048886:	68 38 00 00 00       	push   $0x38
 804888b:	e9 70 ff ff ff       	jmp    8048800 <_init+0x28>

08048890 <alarm@plt>:
 8048890:	ff 25 2c d0 04 08    	jmp    *0x804d02c
 8048896:	68 40 00 00 00       	push   $0x40
 804889b:	e9 60 ff ff ff       	jmp    8048800 <_init+0x28>

080488a0 <_IO_getc@plt>:
 80488a0:	ff 25 30 d0 04 08    	jmp    *0x804d030
 80488a6:	68 48 00 00 00       	push   $0x48
 80488ab:	e9 50 ff ff ff       	jmp    8048800 <_init+0x28>

080488b0 <htons@plt>:
 80488b0:	ff 25 34 d0 04 08    	jmp    *0x804d034
 80488b6:	68 50 00 00 00       	push   $0x50
 80488bb:	e9 40 ff ff ff       	jmp    8048800 <_init+0x28>

080488c0 <fwrite@plt>:
 80488c0:	ff 25 38 d0 04 08    	jmp    *0x804d038
 80488c6:	68 58 00 00 00       	push   $0x58
 80488cb:	e9 30 ff ff ff       	jmp    8048800 <_init+0x28>

080488d0 <bcopy@plt>:
 80488d0:	ff 25 3c d0 04 08    	jmp    *0x804d03c
 80488d6:	68 60 00 00 00       	push   $0x60
 80488db:	e9 20 ff ff ff       	jmp    8048800 <_init+0x28>

080488e0 <strcpy@plt>:
 80488e0:	ff 25 40 d0 04 08    	jmp    *0x804d040
 80488e6:	68 68 00 00 00       	push   $0x68
 80488eb:	e9 10 ff ff ff       	jmp    8048800 <_init+0x28>

080488f0 <getpid@plt>:
 80488f0:	ff 25 44 d0 04 08    	jmp    *0x804d044
 80488f6:	68 70 00 00 00       	push   $0x70
 80488fb:	e9 00 ff ff ff       	jmp    8048800 <_init+0x28>

08048900 <gethostname@plt>:
 8048900:	ff 25 48 d0 04 08    	jmp    *0x804d048
 8048906:	68 78 00 00 00       	push   $0x78
 804890b:	e9 f0 fe ff ff       	jmp    8048800 <_init+0x28>

08048910 <puts@plt>:
 8048910:	ff 25 4c d0 04 08    	jmp    *0x804d04c
 8048916:	68 80 00 00 00       	push   $0x80
 804891b:	e9 e0 fe ff ff       	jmp    8048800 <_init+0x28>

08048920 <exit@plt>:
 8048920:	ff 25 50 d0 04 08    	jmp    *0x804d050
 8048926:	68 88 00 00 00       	push   $0x88
 804892b:	e9 d0 fe ff ff       	jmp    8048800 <_init+0x28>

08048930 <srand@plt>:
 8048930:	ff 25 54 d0 04 08    	jmp    *0x804d054
 8048936:	68 90 00 00 00       	push   $0x90
 804893b:	e9 c0 fe ff ff       	jmp    8048800 <_init+0x28>

08048940 <mmap@plt>:
 8048940:	ff 25 58 d0 04 08    	jmp    *0x804d058
 8048946:	68 98 00 00 00       	push   $0x98
 804894b:	e9 b0 fe ff ff       	jmp    8048800 <_init+0x28>

08048950 <strlen@plt>:
 8048950:	ff 25 5c d0 04 08    	jmp    *0x804d05c
 8048956:	68 a0 00 00 00       	push   $0xa0
 804895b:	e9 a0 fe ff ff       	jmp    8048800 <_init+0x28>

08048960 <__libc_start_main@plt>:
 8048960:	ff 25 60 d0 04 08    	jmp    *0x804d060
 8048966:	68 a8 00 00 00       	push   $0xa8
 804896b:	e9 90 fe ff ff       	jmp    8048800 <_init+0x28>

08048970 <write@plt>:
 8048970:	ff 25 64 d0 04 08    	jmp    *0x804d064
 8048976:	68 b0 00 00 00       	push   $0xb0
 804897b:	e9 80 fe ff ff       	jmp    8048800 <_init+0x28>

08048980 <getopt@plt>:
 8048980:	ff 25 68 d0 04 08    	jmp    *0x804d068
 8048986:	68 b8 00 00 00       	push   $0xb8
 804898b:	e9 70 fe ff ff       	jmp    8048800 <_init+0x28>

08048990 <strcasecmp@plt>:
 8048990:	ff 25 6c d0 04 08    	jmp    *0x804d06c
 8048996:	68 c0 00 00 00       	push   $0xc0
 804899b:	e9 60 fe ff ff       	jmp    8048800 <_init+0x28>

080489a0 <__isoc99_sscanf@plt>:
 80489a0:	ff 25 70 d0 04 08    	jmp    *0x804d070
 80489a6:	68 c8 00 00 00       	push   $0xc8
 80489ab:	e9 50 fe ff ff       	jmp    8048800 <_init+0x28>

080489b0 <memset@plt>:
 80489b0:	ff 25 74 d0 04 08    	jmp    *0x804d074
 80489b6:	68 d0 00 00 00       	push   $0xd0
 80489bb:	e9 40 fe ff ff       	jmp    8048800 <_init+0x28>

080489c0 <__errno_location@plt>:
 80489c0:	ff 25 78 d0 04 08    	jmp    *0x804d078
 80489c6:	68 d8 00 00 00       	push   $0xd8
 80489cb:	e9 30 fe ff ff       	jmp    8048800 <_init+0x28>

080489d0 <rand@plt>:
 80489d0:	ff 25 7c d0 04 08    	jmp    *0x804d07c
 80489d6:	68 e0 00 00 00       	push   $0xe0
 80489db:	e9 20 fe ff ff       	jmp    8048800 <_init+0x28>

080489e0 <munmap@plt>:
 80489e0:	ff 25 80 d0 04 08    	jmp    *0x804d080
 80489e6:	68 e8 00 00 00       	push   $0xe8
 80489eb:	e9 10 fe ff ff       	jmp    8048800 <_init+0x28>

080489f0 <sprintf@plt>:
 80489f0:	ff 25 84 d0 04 08    	jmp    *0x804d084
 80489f6:	68 f0 00 00 00       	push   $0xf0
 80489fb:	e9 00 fe ff ff       	jmp    8048800 <_init+0x28>

08048a00 <socket@plt>:
 8048a00:	ff 25 88 d0 04 08    	jmp    *0x804d088
 8048a06:	68 f8 00 00 00       	push   $0xf8
 8048a0b:	e9 f0 fd ff ff       	jmp    8048800 <_init+0x28>

08048a10 <random@plt>:
 8048a10:	ff 25 8c d0 04 08    	jmp    *0x804d08c
 8048a16:	68 00 01 00 00       	push   $0x100
 8048a1b:	e9 e0 fd ff ff       	jmp    8048800 <_init+0x28>

08048a20 <gethostbyname@plt>:
 8048a20:	ff 25 90 d0 04 08    	jmp    *0x804d090
 8048a26:	68 08 01 00 00       	push   $0x108
 8048a2b:	e9 d0 fd ff ff       	jmp    8048800 <_init+0x28>

08048a30 <connect@plt>:
 8048a30:	ff 25 94 d0 04 08    	jmp    *0x804d094
 8048a36:	68 10 01 00 00       	push   $0x110
 8048a3b:	e9 c0 fd ff ff       	jmp    8048800 <_init+0x28>

08048a40 <close@plt>:
 8048a40:	ff 25 98 d0 04 08    	jmp    *0x804d098
 8048a46:	68 18 01 00 00       	push   $0x118
 8048a4b:	e9 b0 fd ff ff       	jmp    8048800 <_init+0x28>

08048a50 <calloc@plt>:
 8048a50:	ff 25 9c d0 04 08    	jmp    *0x804d09c
 8048a56:	68 20 01 00 00       	push   $0x120
 8048a5b:	e9 a0 fd ff ff       	jmp    8048800 <_init+0x28>

Disassembly of section .plt.got:

08048a60 <.plt.got>:
 8048a60:	ff 25 fc cf 04 08    	jmp    *0x804cffc
 8048a66:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

08048a70 <_start>:
 8048a70:	31 ed                	xor    %ebp,%ebp
 8048a72:	5e                   	pop    %esi
 8048a73:	89 e1                	mov    %esp,%ecx
 8048a75:	83 e4 f0             	and    $0xfffffff0,%esp
 8048a78:	50                   	push   %eax
 8048a79:	54                   	push   %esp
 8048a7a:	52                   	push   %edx
 8048a7b:	68 c0 a2 04 08       	push   $0x804a2c0
 8048a80:	68 60 a2 04 08       	push   $0x804a260
 8048a85:	51                   	push   %ecx
 8048a86:	56                   	push   %esi
 8048a87:	68 ee 90 04 08       	push   $0x80490ee
 8048a8c:	e8 cf fe ff ff       	call   8048960 <__libc_start_main@plt>
 8048a91:	f4                   	hlt    
 8048a92:	66 90                	xchg   %ax,%ax
 8048a94:	66 90                	xchg   %ax,%ax
 8048a96:	66 90                	xchg   %ax,%ax
 8048a98:	66 90                	xchg   %ax,%ax
 8048a9a:	66 90                	xchg   %ax,%ax
 8048a9c:	66 90                	xchg   %ax,%ax
 8048a9e:	66 90                	xchg   %ax,%ax

08048aa0 <__x86.get_pc_thunk.bx>:
 8048aa0:	8b 1c 24             	mov    (%esp),%ebx
 8048aa3:	c3                   	ret    
 8048aa4:	66 90                	xchg   %ax,%ax
 8048aa6:	66 90                	xchg   %ax,%ax
 8048aa8:	66 90                	xchg   %ax,%ax
 8048aaa:	66 90                	xchg   %ax,%ax
 8048aac:	66 90                	xchg   %ax,%ax
 8048aae:	66 90                	xchg   %ax,%ax

08048ab0 <deregister_tm_clones>:
 8048ab0:	b8 d7 e0 04 08       	mov    $0x804e0d7,%eax
 8048ab5:	2d d4 e0 04 08       	sub    $0x804e0d4,%eax
 8048aba:	83 f8 06             	cmp    $0x6,%eax
 8048abd:	76 1a                	jbe    8048ad9 <deregister_tm_clones+0x29>
 8048abf:	b8 00 00 00 00       	mov    $0x0,%eax
 8048ac4:	85 c0                	test   %eax,%eax
 8048ac6:	74 11                	je     8048ad9 <deregister_tm_clones+0x29>
 8048ac8:	55                   	push   %ebp
 8048ac9:	89 e5                	mov    %esp,%ebp
 8048acb:	83 ec 14             	sub    $0x14,%esp
 8048ace:	68 d4 e0 04 08       	push   $0x804e0d4
 8048ad3:	ff d0                	call   *%eax
 8048ad5:	83 c4 10             	add    $0x10,%esp
 8048ad8:	c9                   	leave  
 8048ad9:	f3 c3                	repz ret 
 8048adb:	90                   	nop
 8048adc:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi

08048ae0 <register_tm_clones>:
 8048ae0:	b8 d4 e0 04 08       	mov    $0x804e0d4,%eax
 8048ae5:	2d d4 e0 04 08       	sub    $0x804e0d4,%eax
 8048aea:	c1 f8 02             	sar    $0x2,%eax
 8048aed:	89 c2                	mov    %eax,%edx
 8048aef:	c1 ea 1f             	shr    $0x1f,%edx
 8048af2:	01 d0                	add    %edx,%eax
 8048af4:	d1 f8                	sar    %eax
 8048af6:	74 1b                	je     8048b13 <register_tm_clones+0x33>
 8048af8:	ba 00 00 00 00       	mov    $0x0,%edx
 8048afd:	85 d2                	test   %edx,%edx
 8048aff:	74 12                	je     8048b13 <register_tm_clones+0x33>
 8048b01:	55                   	push   %ebp
 8048b02:	89 e5                	mov    %esp,%ebp
 8048b04:	83 ec 10             	sub    $0x10,%esp
 8048b07:	50                   	push   %eax
 8048b08:	68 d4 e0 04 08       	push   $0x804e0d4
 8048b0d:	ff d2                	call   *%edx
 8048b0f:	83 c4 10             	add    $0x10,%esp
 8048b12:	c9                   	leave  
 8048b13:	f3 c3                	repz ret 
 8048b15:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 8048b19:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

08048b20 <__do_global_dtors_aux>:
 8048b20:	80 3d 24 e1 04 08 00 	cmpb   $0x0,0x804e124
 8048b27:	75 13                	jne    8048b3c <__do_global_dtors_aux+0x1c>
 8048b29:	55                   	push   %ebp
 8048b2a:	89 e5                	mov    %esp,%ebp
 8048b2c:	83 ec 08             	sub    $0x8,%esp
 8048b2f:	e8 7c ff ff ff       	call   8048ab0 <deregister_tm_clones>
 8048b34:	c6 05 24 e1 04 08 01 	movb   $0x1,0x804e124
 8048b3b:	c9                   	leave  
 8048b3c:	f3 c3                	repz ret 
 8048b3e:	66 90                	xchg   %ax,%ax

08048b40 <frame_dummy>:
 8048b40:	b8 10 cf 04 08       	mov    $0x804cf10,%eax
 8048b45:	8b 10                	mov    (%eax),%edx
 8048b47:	85 d2                	test   %edx,%edx
 8048b49:	75 05                	jne    8048b50 <frame_dummy+0x10>
 8048b4b:	eb 93                	jmp    8048ae0 <register_tm_clones>
 8048b4d:	8d 76 00             	lea    0x0(%esi),%esi
 8048b50:	ba 00 00 00 00       	mov    $0x0,%edx
 8048b55:	85 d2                	test   %edx,%edx
 8048b57:	74 f2                	je     8048b4b <frame_dummy+0xb>
 8048b59:	55                   	push   %ebp
 8048b5a:	89 e5                	mov    %esp,%ebp
 8048b5c:	83 ec 14             	sub    $0x14,%esp
 8048b5f:	50                   	push   %eax
 8048b60:	ff d2                	call   *%edx
 8048b62:	83 c4 10             	add    $0x10,%esp
 8048b65:	c9                   	leave  
 8048b66:	e9 75 ff ff ff       	jmp    8048ae0 <register_tm_clones>

08048b6b <smoke>:
 8048b6b:	55                   	push   %ebp
 8048b6c:	89 e5                	mov    %esp,%ebp
 8048b6e:	83 ec 08             	sub    $0x8,%esp
 8048b71:	83 ec 0c             	sub    $0xc,%esp
 8048b74:	68 e0 a2 04 08       	push   $0x804a2e0
 8048b79:	e8 92 fd ff ff       	call   8048910 <puts@plt>
 8048b7e:	83 c4 10             	add    $0x10,%esp
 8048b81:	83 ec 0c             	sub    $0xc,%esp
 8048b84:	6a 00                	push   $0x0
 8048b86:	e8 ec 08 00 00       	call   8049477 <validate>
 8048b8b:	83 c4 10             	add    $0x10,%esp
 8048b8e:	83 ec 0c             	sub    $0xc,%esp
 8048b91:	6a 00                	push   $0x0
 8048b93:	e8 88 fd ff ff       	call   8048920 <exit@plt>

08048b98 <fizz>:
 8048b98:	55                   	push   %ebp
 8048b99:	89 e5                	mov    %esp,%ebp
 8048b9b:	83 ec 08             	sub    $0x8,%esp
 8048b9e:	8b 55 08             	mov    0x8(%ebp),%edx
 8048ba1:	a1 38 e1 04 08       	mov    0x804e138,%eax
 8048ba6:	39 c2                	cmp    %eax,%edx
 8048ba8:	75 22                	jne    8048bcc <fizz+0x34>
 8048baa:	83 ec 08             	sub    $0x8,%esp
 8048bad:	ff 75 08             	pushl  0x8(%ebp)
 8048bb0:	68 fb a2 04 08       	push   $0x804a2fb
 8048bb5:	e8 86 fc ff ff       	call   8048840 <printf@plt>
 8048bba:	83 c4 10             	add    $0x10,%esp
 8048bbd:	83 ec 0c             	sub    $0xc,%esp
 8048bc0:	6a 01                	push   $0x1
 8048bc2:	e8 b0 08 00 00       	call   8049477 <validate>
 8048bc7:	83 c4 10             	add    $0x10,%esp
 8048bca:	eb 13                	jmp    8048bdf <fizz+0x47>
 8048bcc:	83 ec 08             	sub    $0x8,%esp
 8048bcf:	ff 75 08             	pushl  0x8(%ebp)
 8048bd2:	68 1c a3 04 08       	push   $0x804a31c
 8048bd7:	e8 64 fc ff ff       	call   8048840 <printf@plt>
 8048bdc:	83 c4 10             	add    $0x10,%esp
 8048bdf:	83 ec 0c             	sub    $0xc,%esp
 8048be2:	6a 00                	push   $0x0
 8048be4:	e8 37 fd ff ff       	call   8048920 <exit@plt>

08048be9 <bang>:
 8048be9:	55                   	push   %ebp
 8048bea:	89 e5                	mov    %esp,%ebp
 8048bec:	83 ec 08             	sub    $0x8,%esp
 8048bef:	a1 40 e1 04 08       	mov    0x804e140,%eax
 8048bf4:	89 c2                	mov    %eax,%edx
 8048bf6:	a1 38 e1 04 08       	mov    0x804e138,%eax
 8048bfb:	39 c2                	cmp    %eax,%edx
 8048bfd:	75 25                	jne    8048c24 <bang+0x3b>
 8048bff:	a1 40 e1 04 08       	mov    0x804e140,%eax
 8048c04:	83 ec 08             	sub    $0x8,%esp
 8048c07:	50                   	push   %eax
 8048c08:	68 3c a3 04 08       	push   $0x804a33c
 8048c0d:	e8 2e fc ff ff       	call   8048840 <printf@plt>
 8048c12:	83 c4 10             	add    $0x10,%esp
 8048c15:	83 ec 0c             	sub    $0xc,%esp
 8048c18:	6a 02                	push   $0x2
 8048c1a:	e8 58 08 00 00       	call   8049477 <validate>
 8048c1f:	83 c4 10             	add    $0x10,%esp
 8048c22:	eb 16                	jmp    8048c3a <bang+0x51>
 8048c24:	a1 40 e1 04 08       	mov    0x804e140,%eax
 8048c29:	83 ec 08             	sub    $0x8,%esp
 8048c2c:	50                   	push   %eax
 8048c2d:	68 61 a3 04 08       	push   $0x804a361
 8048c32:	e8 09 fc ff ff       	call   8048840 <printf@plt>
 8048c37:	83 c4 10             	add    $0x10,%esp
 8048c3a:	83 ec 0c             	sub    $0xc,%esp
 8048c3d:	6a 00                	push   $0x0
 8048c3f:	e8 dc fc ff ff       	call   8048920 <exit@plt>

08048c44 <test>:
 8048c44:	55                   	push   %ebp
 8048c45:	89 e5                	mov    %esp,%ebp
 8048c47:	83 ec 18             	sub    $0x18,%esp
 8048c4a:	e8 81 04 00 00       	call   80490d0 <uniqueval>
 8048c4f:	89 45 f0             	mov    %eax,-0x10(%ebp)
 8048c52:	e8 67 00 00 00       	call   8048cbe <getbuf>
 8048c57:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8048c5a:	e8 71 04 00 00       	call   80490d0 <uniqueval>
 8048c5f:	89 c2                	mov    %eax,%edx
 8048c61:	8b 45 f0             	mov    -0x10(%ebp),%eax
 8048c64:	39 c2                	cmp    %eax,%edx
 8048c66:	74 12                	je     8048c7a <test+0x36>
 8048c68:	83 ec 0c             	sub    $0xc,%esp
 8048c6b:	68 80 a3 04 08       	push   $0x804a380
 8048c70:	e8 9b fc ff ff       	call   8048910 <puts@plt>
 8048c75:	83 c4 10             	add    $0x10,%esp
 8048c78:	eb 41                	jmp    8048cbb <test+0x77>
 8048c7a:	8b 55 f4             	mov    -0xc(%ebp),%edx
 8048c7d:	a1 38 e1 04 08       	mov    0x804e138,%eax
 8048c82:	39 c2                	cmp    %eax,%edx
 8048c84:	75 22                	jne    8048ca8 <test+0x64>
 8048c86:	83 ec 08             	sub    $0x8,%esp
 8048c89:	ff 75 f4             	pushl  -0xc(%ebp)
 8048c8c:	68 a9 a3 04 08       	push   $0x804a3a9
 8048c91:	e8 aa fb ff ff       	call   8048840 <printf@plt>
 8048c96:	83 c4 10             	add    $0x10,%esp
 8048c99:	83 ec 0c             	sub    $0xc,%esp
 8048c9c:	6a 03                	push   $0x3
 8048c9e:	e8 d4 07 00 00       	call   8049477 <validate>
 8048ca3:	83 c4 10             	add    $0x10,%esp
 8048ca6:	eb 13                	jmp    8048cbb <test+0x77>
 8048ca8:	83 ec 08             	sub    $0x8,%esp
 8048cab:	ff 75 f4             	pushl  -0xc(%ebp)
 8048cae:	68 c6 a3 04 08       	push   $0x804a3c6
 8048cb3:	e8 88 fb ff ff       	call   8048840 <printf@plt>
 8048cb8:	83 c4 10             	add    $0x10,%esp
 8048cbb:	90                   	nop
 8048cbc:	c9                   	leave  
 8048cbd:	c3                   	ret    

08048cbe <getbuf>:
 8048cbe:	55                   	push   %ebp
 8048cbf:	89 e5                	mov    %esp,%ebp
 8048cc1:	83 ec 28             	sub    $0x28,%esp
 8048cc4:	83 ec 0c             	sub    $0xc,%esp
 8048cc7:	8d 45 d8             	lea    -0x28(%ebp),%eax
 8048cca:	50                   	push   %eax
 8048ccb:	e8 41 01 00 00       	call   8048e11 <Gets>
 8048cd0:	83 c4 10             	add    $0x10,%esp
 8048cd3:	b8 01 00 00 00       	mov    $0x1,%eax
 8048cd8:	c9                   	leave  
 8048cd9:	c3                   	ret    

08048cda <getbufn>:
 8048cda:	55                   	push   %ebp
 8048cdb:	89 e5                	mov    %esp,%ebp
 8048cdd:	81 ec 08 02 00 00    	sub    $0x208,%esp
 8048ce3:	83 ec 0c             	sub    $0xc,%esp
 8048ce6:	8d 85 f8 fd ff ff    	lea    -0x208(%ebp),%eax
 8048cec:	50                   	push   %eax
 8048ced:	e8 1f 01 00 00       	call   8048e11 <Gets>
 8048cf2:	83 c4 10             	add    $0x10,%esp
 8048cf5:	b8 01 00 00 00       	mov    $0x1,%eax
 8048cfa:	c9                   	leave  
 8048cfb:	c3                   	ret    

08048cfc <testn>:
 8048cfc:	55                   	push   %ebp
 8048cfd:	89 e5                	mov    %esp,%ebp
 8048cff:	83 ec 18             	sub    $0x18,%esp
 8048d02:	c7 45 f0 ef be ad de 	movl   $0xdeadbeef,-0x10(%ebp)
 8048d09:	e8 cc ff ff ff       	call   8048cda <getbufn>
 8048d0e:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8048d11:	8b 45 f0             	mov    -0x10(%ebp),%eax
 8048d14:	3d ef be ad de       	cmp    $0xdeadbeef,%eax
 8048d19:	74 12                	je     8048d2d <testn+0x31>
 8048d1b:	83 ec 0c             	sub    $0xc,%esp
 8048d1e:	68 80 a3 04 08       	push   $0x804a380
 8048d23:	e8 e8 fb ff ff       	call   8048910 <puts@plt>
 8048d28:	83 c4 10             	add    $0x10,%esp
 8048d2b:	eb 41                	jmp    8048d6e <testn+0x72>
 8048d2d:	8b 55 f4             	mov    -0xc(%ebp),%edx
 8048d30:	a1 38 e1 04 08       	mov    0x804e138,%eax
 8048d35:	39 c2                	cmp    %eax,%edx
 8048d37:	75 22                	jne    8048d5b <testn+0x5f>
 8048d39:	83 ec 08             	sub    $0x8,%esp
 8048d3c:	ff 75 f4             	pushl  -0xc(%ebp)
 8048d3f:	68 e4 a3 04 08       	push   $0x804a3e4
 8048d44:	e8 f7 fa ff ff       	call   8048840 <printf@plt>
 8048d49:	83 c4 10             	add    $0x10,%esp
 8048d4c:	83 ec 0c             	sub    $0xc,%esp
 8048d4f:	6a 04                	push   $0x4
 8048d51:	e8 21 07 00 00       	call   8049477 <validate>
 8048d56:	83 c4 10             	add    $0x10,%esp
 8048d59:	eb 13                	jmp    8048d6e <testn+0x72>
 8048d5b:	83 ec 08             	sub    $0x8,%esp
 8048d5e:	ff 75 f4             	pushl  -0xc(%ebp)
 8048d61:	68 04 a4 04 08       	push   $0x804a404
 8048d66:	e8 d5 fa ff ff       	call   8048840 <printf@plt>
 8048d6b:	83 c4 10             	add    $0x10,%esp
 8048d6e:	90                   	nop
 8048d6f:	c9                   	leave  
 8048d70:	c3                   	ret    

08048d71 <save_char>:
 8048d71:	55                   	push   %ebp
 8048d72:	89 e5                	mov    %esp,%ebp
 8048d74:	83 ec 04             	sub    $0x4,%esp
 8048d77:	8b 45 08             	mov    0x8(%ebp),%eax
 8048d7a:	88 45 fc             	mov    %al,-0x4(%ebp)
 8048d7d:	a1 44 e1 04 08       	mov    0x804e144,%eax
 8048d82:	3d ff 03 00 00       	cmp    $0x3ff,%eax
 8048d87:	7f 6c                	jg     8048df5 <save_char+0x84>
 8048d89:	8b 15 44 e1 04 08    	mov    0x804e144,%edx
 8048d8f:	89 d0                	mov    %edx,%eax
 8048d91:	01 c0                	add    %eax,%eax
 8048d93:	01 c2                	add    %eax,%edx
 8048d95:	0f b6 45 fc          	movzbl -0x4(%ebp),%eax
 8048d99:	c0 f8 04             	sar    $0x4,%al
 8048d9c:	0f be c0             	movsbl %al,%eax
 8048d9f:	83 e0 0f             	and    $0xf,%eax
 8048da2:	0f b6 80 a8 d0 04 08 	movzbl 0x804d0a8(%eax),%eax
 8048da9:	88 82 80 e1 04 08    	mov    %al,0x804e180(%edx)
 8048daf:	8b 15 44 e1 04 08    	mov    0x804e144,%edx
 8048db5:	89 d0                	mov    %edx,%eax
 8048db7:	01 c0                	add    %eax,%eax
 8048db9:	01 d0                	add    %edx,%eax
 8048dbb:	8d 50 01             	lea    0x1(%eax),%edx
 8048dbe:	0f be 45 fc          	movsbl -0x4(%ebp),%eax
 8048dc2:	83 e0 0f             	and    $0xf,%eax
 8048dc5:	0f b6 80 a8 d0 04 08 	movzbl 0x804d0a8(%eax),%eax
 8048dcc:	88 82 80 e1 04 08    	mov    %al,0x804e180(%edx)
 8048dd2:	8b 15 44 e1 04 08    	mov    0x804e144,%edx
 8048dd8:	89 d0                	mov    %edx,%eax
 8048dda:	01 c0                	add    %eax,%eax
 8048ddc:	01 d0                	add    %edx,%eax
 8048dde:	83 c0 02             	add    $0x2,%eax
 8048de1:	c6 80 80 e1 04 08 20 	movb   $0x20,0x804e180(%eax)
 8048de8:	a1 44 e1 04 08       	mov    0x804e144,%eax
 8048ded:	83 c0 01             	add    $0x1,%eax
 8048df0:	a3 44 e1 04 08       	mov    %eax,0x804e144
 8048df5:	90                   	nop
 8048df6:	c9                   	leave  
 8048df7:	c3                   	ret    

08048df8 <save_term>:
 8048df8:	55                   	push   %ebp
 8048df9:	89 e5                	mov    %esp,%ebp
 8048dfb:	8b 15 44 e1 04 08    	mov    0x804e144,%edx
 8048e01:	89 d0                	mov    %edx,%eax
 8048e03:	01 c0                	add    %eax,%eax
 8048e05:	01 d0                	add    %edx,%eax
 8048e07:	c6 80 80 e1 04 08 00 	movb   $0x0,0x804e180(%eax)
 8048e0e:	90                   	nop
 8048e0f:	5d                   	pop    %ebp
 8048e10:	c3                   	ret    

08048e11 <Gets>:
 8048e11:	55                   	push   %ebp
 8048e12:	89 e5                	mov    %esp,%ebp
 8048e14:	83 ec 18             	sub    $0x18,%esp
 8048e17:	8b 45 08             	mov    0x8(%ebp),%eax
 8048e1a:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8048e1d:	c7 05 44 e1 04 08 00 	movl   $0x0,0x804e144
 8048e24:	00 00 00 
 8048e27:	eb 1d                	jmp    8048e46 <Gets+0x35>
 8048e29:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8048e2c:	8d 50 01             	lea    0x1(%eax),%edx
 8048e2f:	89 55 f4             	mov    %edx,-0xc(%ebp)
 8048e32:	8b 55 f0             	mov    -0x10(%ebp),%edx
 8048e35:	88 10                	mov    %dl,(%eax)
 8048e37:	8b 45 f0             	mov    -0x10(%ebp),%eax
 8048e3a:	0f be c0             	movsbl %al,%eax
 8048e3d:	50                   	push   %eax
 8048e3e:	e8 2e ff ff ff       	call   8048d71 <save_char>
 8048e43:	83 c4 04             	add    $0x4,%esp
 8048e46:	a1 34 e1 04 08       	mov    0x804e134,%eax
 8048e4b:	83 ec 0c             	sub    $0xc,%esp
 8048e4e:	50                   	push   %eax
 8048e4f:	e8 4c fa ff ff       	call   80488a0 <_IO_getc@plt>
 8048e54:	83 c4 10             	add    $0x10,%esp
 8048e57:	89 45 f0             	mov    %eax,-0x10(%ebp)
 8048e5a:	83 7d f0 ff          	cmpl   $0xffffffff,-0x10(%ebp)
 8048e5e:	74 06                	je     8048e66 <Gets+0x55>
 8048e60:	83 7d f0 0a          	cmpl   $0xa,-0x10(%ebp)
 8048e64:	75 c3                	jne    8048e29 <Gets+0x18>
 8048e66:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8048e69:	8d 50 01             	lea    0x1(%eax),%edx
 8048e6c:	89 55 f4             	mov    %edx,-0xc(%ebp)
 8048e6f:	c6 00 00             	movb   $0x0,(%eax)
 8048e72:	e8 81 ff ff ff       	call   8048df8 <save_term>
 8048e77:	8b 45 08             	mov    0x8(%ebp),%eax
 8048e7a:	c9                   	leave  
 8048e7b:	c3                   	ret    

08048e7c <usage>:
 8048e7c:	55                   	push   %ebp
 8048e7d:	89 e5                	mov    %esp,%ebp
 8048e7f:	83 ec 08             	sub    $0x8,%esp
 8048e82:	83 ec 08             	sub    $0x8,%esp
 8048e85:	ff 75 08             	pushl  0x8(%ebp)
 8048e88:	68 20 a4 04 08       	push   $0x804a420
 8048e8d:	e8 ae f9 ff ff       	call   8048840 <printf@plt>
 8048e92:	83 c4 10             	add    $0x10,%esp
 8048e95:	83 ec 0c             	sub    $0xc,%esp
 8048e98:	68 3e a4 04 08       	push   $0x804a43e
 8048e9d:	e8 6e fa ff ff       	call   8048910 <puts@plt>
 8048ea2:	83 c4 10             	add    $0x10,%esp
 8048ea5:	83 ec 0c             	sub    $0xc,%esp
 8048ea8:	68 54 a4 04 08       	push   $0x804a454
 8048ead:	e8 5e fa ff ff       	call   8048910 <puts@plt>
 8048eb2:	83 c4 10             	add    $0x10,%esp
 8048eb5:	83 ec 0c             	sub    $0xc,%esp
 8048eb8:	68 70 a4 04 08       	push   $0x804a470
 8048ebd:	e8 4e fa ff ff       	call   8048910 <puts@plt>
 8048ec2:	83 c4 10             	add    $0x10,%esp
 8048ec5:	83 ec 0c             	sub    $0xc,%esp
 8048ec8:	68 ac a4 04 08       	push   $0x804a4ac
 8048ecd:	e8 3e fa ff ff       	call   8048910 <puts@plt>
 8048ed2:	83 c4 10             	add    $0x10,%esp
 8048ed5:	83 ec 0c             	sub    $0xc,%esp
 8048ed8:	6a 00                	push   $0x0
 8048eda:	e8 41 fa ff ff       	call   8048920 <exit@plt>

08048edf <bushandler>:
 8048edf:	55                   	push   %ebp
 8048ee0:	89 e5                	mov    %esp,%ebp
 8048ee2:	83 ec 08             	sub    $0x8,%esp
 8048ee5:	83 ec 0c             	sub    $0xc,%esp
 8048ee8:	68 d4 a4 04 08       	push   $0x804a4d4
 8048eed:	e8 1e fa ff ff       	call   8048910 <puts@plt>
 8048ef2:	83 c4 10             	add    $0x10,%esp
 8048ef5:	83 ec 0c             	sub    $0xc,%esp
 8048ef8:	68 f4 a4 04 08       	push   $0x804a4f4
 8048efd:	e8 0e fa ff ff       	call   8048910 <puts@plt>
 8048f02:	83 c4 10             	add    $0x10,%esp
 8048f05:	83 ec 0c             	sub    $0xc,%esp
 8048f08:	6a 00                	push   $0x0
 8048f0a:	e8 11 fa ff ff       	call   8048920 <exit@plt>

08048f0f <seghandler>:
 8048f0f:	55                   	push   %ebp
 8048f10:	89 e5                	mov    %esp,%ebp
 8048f12:	83 ec 08             	sub    $0x8,%esp
 8048f15:	83 ec 0c             	sub    $0xc,%esp
 8048f18:	68 0c a5 04 08       	push   $0x804a50c
 8048f1d:	e8 ee f9 ff ff       	call   8048910 <puts@plt>
 8048f22:	83 c4 10             	add    $0x10,%esp
 8048f25:	83 ec 0c             	sub    $0xc,%esp
 8048f28:	68 f4 a4 04 08       	push   $0x804a4f4
 8048f2d:	e8 de f9 ff ff       	call   8048910 <puts@plt>
 8048f32:	83 c4 10             	add    $0x10,%esp
 8048f35:	83 ec 0c             	sub    $0xc,%esp
 8048f38:	6a 00                	push   $0x0
 8048f3a:	e8 e1 f9 ff ff       	call   8048920 <exit@plt>

08048f3f <illegalhandler>:
 8048f3f:	55                   	push   %ebp
 8048f40:	89 e5                	mov    %esp,%ebp
 8048f42:	83 ec 08             	sub    $0x8,%esp
 8048f45:	83 ec 0c             	sub    $0xc,%esp
 8048f48:	68 34 a5 04 08       	push   $0x804a534
 8048f4d:	e8 be f9 ff ff       	call   8048910 <puts@plt>
 8048f52:	83 c4 10             	add    $0x10,%esp
 8048f55:	83 ec 0c             	sub    $0xc,%esp
 8048f58:	68 f4 a4 04 08       	push   $0x804a4f4
 8048f5d:	e8 ae f9 ff ff       	call   8048910 <puts@plt>
 8048f62:	83 c4 10             	add    $0x10,%esp
 8048f65:	83 ec 0c             	sub    $0xc,%esp
 8048f68:	6a 00                	push   $0x0
 8048f6a:	e8 b1 f9 ff ff       	call   8048920 <exit@plt>

08048f6f <launch>:
 8048f6f:	55                   	push   %ebp
 8048f70:	89 e5                	mov    %esp,%ebp
 8048f72:	83 ec 58             	sub    $0x58,%esp
 8048f75:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 8048f7c:	8d 45 b0             	lea    -0x50(%ebp),%eax
 8048f7f:	25 f0 3f 00 00       	and    $0x3ff0,%eax
 8048f84:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8048f87:	8b 55 0c             	mov    0xc(%ebp),%edx
 8048f8a:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8048f8d:	01 d0                	add    %edx,%eax
 8048f8f:	8d 50 0f             	lea    0xf(%eax),%edx
 8048f92:	b8 10 00 00 00       	mov    $0x10,%eax
 8048f97:	83 e8 01             	sub    $0x1,%eax
 8048f9a:	01 d0                	add    %edx,%eax
 8048f9c:	b9 10 00 00 00       	mov    $0x10,%ecx
 8048fa1:	ba 00 00 00 00       	mov    $0x0,%edx
 8048fa6:	f7 f1                	div    %ecx
 8048fa8:	6b c0 10             	imul   $0x10,%eax,%eax
 8048fab:	29 c4                	sub    %eax,%esp
 8048fad:	89 e0                	mov    %esp,%eax
 8048faf:	83 c0 0f             	add    $0xf,%eax
 8048fb2:	c1 e8 04             	shr    $0x4,%eax
 8048fb5:	c1 e0 04             	shl    $0x4,%eax
 8048fb8:	89 45 f0             	mov    %eax,-0x10(%ebp)
 8048fbb:	83 ec 04             	sub    $0x4,%esp
 8048fbe:	ff 75 f4             	pushl  -0xc(%ebp)
 8048fc1:	68 f4 00 00 00       	push   $0xf4
 8048fc6:	ff 75 f0             	pushl  -0x10(%ebp)
 8048fc9:	e8 e2 f9 ff ff       	call   80489b0 <memset@plt>
 8048fce:	83 c4 10             	add    $0x10,%esp
 8048fd1:	83 ec 0c             	sub    $0xc,%esp
 8048fd4:	68 5f a5 04 08       	push   $0x804a55f
 8048fd9:	e8 62 f8 ff ff       	call   8048840 <printf@plt>
 8048fde:	83 c4 10             	add    $0x10,%esp
 8048fe1:	83 7d 08 00          	cmpl   $0x0,0x8(%ebp)
 8048fe5:	74 07                	je     8048fee <launch+0x7f>
 8048fe7:	e8 10 fd ff ff       	call   8048cfc <testn>
 8048fec:	eb 05                	jmp    8048ff3 <launch+0x84>
 8048fee:	e8 51 fc ff ff       	call   8048c44 <test>
 8048ff3:	a1 3c e1 04 08       	mov    0x804e13c,%eax
 8048ff8:	85 c0                	test   %eax,%eax
 8048ffa:	75 1a                	jne    8049016 <launch+0xa7>
 8048ffc:	83 ec 0c             	sub    $0xc,%esp
 8048fff:	68 f4 a4 04 08       	push   $0x804a4f4
 8049004:	e8 07 f9 ff ff       	call   8048910 <puts@plt>
 8049009:	83 c4 10             	add    $0x10,%esp
 804900c:	c7 05 3c e1 04 08 00 	movl   $0x0,0x804e13c
 8049013:	00 00 00 
 8049016:	90                   	nop
 8049017:	c9                   	leave  
 8049018:	c3                   	ret    

08049019 <launcher>:
 8049019:	55                   	push   %ebp
 804901a:	89 e5                	mov    %esp,%ebp
 804901c:	83 ec 18             	sub    $0x18,%esp
 804901f:	8b 45 08             	mov    0x8(%ebp),%eax
 8049022:	a3 48 e1 04 08       	mov    %eax,0x804e148
 8049027:	8b 45 0c             	mov    0xc(%ebp),%eax
 804902a:	a3 4c e1 04 08       	mov    %eax,0x804e14c
 804902f:	83 ec 08             	sub    $0x8,%esp
 8049032:	6a 00                	push   $0x0
 8049034:	6a 00                	push   $0x0
 8049036:	68 32 01 00 00       	push   $0x132
 804903b:	6a 07                	push   $0x7
 804903d:	68 00 00 10 00       	push   $0x100000
 8049042:	68 00 60 58 55       	push   $0x55586000
 8049047:	e8 f4 f8 ff ff       	call   8048940 <mmap@plt>
 804904c:	83 c4 20             	add    $0x20,%esp
 804904f:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8049052:	81 7d f4 00 60 58 55 	cmpl   $0x55586000,-0xc(%ebp)
 8049059:	74 21                	je     804907c <launcher+0x63>
 804905b:	a1 e0 e0 04 08       	mov    0x804e0e0,%eax
 8049060:	50                   	push   %eax
 8049061:	6a 47                	push   $0x47
 8049063:	6a 01                	push   $0x1
 8049065:	68 6c a5 04 08       	push   $0x804a56c
 804906a:	e8 51 f8 ff ff       	call   80488c0 <fwrite@plt>
 804906f:	83 c4 10             	add    $0x10,%esp
 8049072:	83 ec 0c             	sub    $0xc,%esp
 8049075:	6a 01                	push   $0x1
 8049077:	e8 a4 f8 ff ff       	call   8048920 <exit@plt>
 804907c:	8b 45 f4             	mov    -0xc(%ebp),%eax
 804907f:	05 f8 ff 0f 00       	add    $0xffff8,%eax
 8049084:	a3 60 e1 04 08       	mov    %eax,0x804e160
 8049089:	8b 15 60 e1 04 08    	mov    0x804e160,%edx
 804908f:	89 e0                	mov    %esp,%eax
 8049091:	89 d4                	mov    %edx,%esp
 8049093:	89 c2                	mov    %eax,%edx
 8049095:	89 15 50 e1 04 08    	mov    %edx,0x804e150
 804909b:	8b 15 4c e1 04 08    	mov    0x804e14c,%edx
 80490a1:	a1 48 e1 04 08       	mov    0x804e148,%eax
 80490a6:	83 ec 08             	sub    $0x8,%esp
 80490a9:	52                   	push   %edx
 80490aa:	50                   	push   %eax
 80490ab:	e8 bf fe ff ff       	call   8048f6f <launch>
 80490b0:	83 c4 10             	add    $0x10,%esp
 80490b3:	a1 50 e1 04 08       	mov    0x804e150,%eax
 80490b8:	89 c4                	mov    %eax,%esp
 80490ba:	83 ec 08             	sub    $0x8,%esp
 80490bd:	68 00 00 10 00       	push   $0x100000
 80490c2:	ff 75 f4             	pushl  -0xc(%ebp)
 80490c5:	e8 16 f9 ff ff       	call   80489e0 <munmap@plt>
 80490ca:	83 c4 10             	add    $0x10,%esp
 80490cd:	90                   	nop
 80490ce:	c9                   	leave  
 80490cf:	c3                   	ret    

080490d0 <uniqueval>:
 80490d0:	55                   	push   %ebp
 80490d1:	89 e5                	mov    %esp,%ebp
 80490d3:	83 ec 08             	sub    $0x8,%esp
 80490d6:	e8 15 f8 ff ff       	call   80488f0 <getpid@plt>
 80490db:	83 ec 0c             	sub    $0xc,%esp
 80490de:	50                   	push   %eax
 80490df:	e8 4c f7 ff ff       	call   8048830 <srandom@plt>
 80490e4:	83 c4 10             	add    $0x10,%esp
 80490e7:	e8 24 f9 ff ff       	call   8048a10 <random@plt>
 80490ec:	c9                   	leave  
 80490ed:	c3                   	ret    

080490ee <main>:
 80490ee:	8d 4c 24 04          	lea    0x4(%esp),%ecx
 80490f2:	83 e4 f0             	and    $0xfffffff0,%esp
 80490f5:	ff 71 fc             	pushl  -0x4(%ecx)
 80490f8:	55                   	push   %ebp
 80490f9:	89 e5                	mov    %esp,%ebp
 80490fb:	53                   	push   %ebx
 80490fc:	51                   	push   %ecx
 80490fd:	83 ec 20             	sub    $0x20,%esp
 8049100:	89 cb                	mov    %ecx,%ebx
 8049102:	c7 45 e8 00 00 00 00 	movl   $0x0,-0x18(%ebp)
 8049109:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 8049110:	c7 45 ec 01 00 00 00 	movl   $0x1,-0x14(%ebp)
 8049117:	83 ec 08             	sub    $0x8,%esp
 804911a:	68 0f 8f 04 08       	push   $0x8048f0f
 804911f:	6a 0b                	push   $0xb
 8049121:	e8 5a f7 ff ff       	call   8048880 <signal@plt>
 8049126:	83 c4 10             	add    $0x10,%esp
 8049129:	83 ec 08             	sub    $0x8,%esp
 804912c:	68 df 8e 04 08       	push   $0x8048edf
 8049131:	6a 07                	push   $0x7
 8049133:	e8 48 f7 ff ff       	call   8048880 <signal@plt>
 8049138:	83 c4 10             	add    $0x10,%esp
 804913b:	83 ec 08             	sub    $0x8,%esp
 804913e:	68 3f 8f 04 08       	push   $0x8048f3f
 8049143:	6a 04                	push   $0x4
 8049145:	e8 36 f7 ff ff       	call   8048880 <signal@plt>
 804914a:	83 c4 10             	add    $0x10,%esp
 804914d:	a1 00 e1 04 08       	mov    0x804e100,%eax
 8049152:	a3 34 e1 04 08       	mov    %eax,0x804e134
 8049157:	e9 8f 00 00 00       	jmp    80491eb <main+0xfd>
 804915c:	0f be 45 e7          	movsbl -0x19(%ebp),%eax
 8049160:	83 e8 67             	sub    $0x67,%eax
 8049163:	83 f8 0e             	cmp    $0xe,%eax
 8049166:	77 72                	ja     80491da <main+0xec>
 8049168:	8b 04 85 04 a6 04 08 	mov    0x804a604(,%eax,4),%eax
 804916f:	ff e0                	jmp    *%eax
 8049171:	8b 43 04             	mov    0x4(%ebx),%eax
 8049174:	8b 00                	mov    (%eax),%eax
 8049176:	83 ec 0c             	sub    $0xc,%esp
 8049179:	50                   	push   %eax
 804917a:	e8 fd fc ff ff       	call   8048e7c <usage>
 804917f:	83 c4 10             	add    $0x10,%esp
 8049182:	eb 67                	jmp    80491eb <main+0xfd>
 8049184:	c7 45 f4 01 00 00 00 	movl   $0x1,-0xc(%ebp)
 804918b:	c7 45 ec 05 00 00 00 	movl   $0x5,-0x14(%ebp)
 8049192:	eb 57                	jmp    80491eb <main+0xfd>
 8049194:	a1 20 e1 04 08       	mov    0x804e120,%eax
 8049199:	83 ec 0c             	sub    $0xc,%esp
 804919c:	50                   	push   %eax
 804919d:	e8 ae f6 ff ff       	call   8048850 <strdup@plt>
 80491a2:	83 c4 10             	add    $0x10,%esp
 80491a5:	a3 28 e1 04 08       	mov    %eax,0x804e128
 80491aa:	a1 28 e1 04 08       	mov    0x804e128,%eax
 80491af:	83 ec 0c             	sub    $0xc,%esp
 80491b2:	50                   	push   %eax
 80491b3:	e8 67 10 00 00       	call   804a21f <gencookie>
 80491b8:	83 c4 10             	add    $0x10,%esp
 80491bb:	a3 38 e1 04 08       	mov    %eax,0x804e138
 80491c0:	eb 29                	jmp    80491eb <main+0xfd>
 80491c2:	c7 05 2c e1 04 08 01 	movl   $0x1,0x804e12c
 80491c9:	00 00 00 
 80491cc:	eb 1d                	jmp    80491eb <main+0xfd>
 80491ce:	c7 05 30 e1 04 08 01 	movl   $0x1,0x804e130
 80491d5:	00 00 00 
 80491d8:	eb 11                	jmp    80491eb <main+0xfd>
 80491da:	8b 43 04             	mov    0x4(%ebx),%eax
 80491dd:	8b 00                	mov    (%eax),%eax
 80491df:	83 ec 0c             	sub    $0xc,%esp
 80491e2:	50                   	push   %eax
 80491e3:	e8 94 fc ff ff       	call   8048e7c <usage>
 80491e8:	83 c4 10             	add    $0x10,%esp
 80491eb:	83 ec 04             	sub    $0x4,%esp
 80491ee:	68 b4 a5 04 08       	push   $0x804a5b4
 80491f3:	ff 73 04             	pushl  0x4(%ebx)
 80491f6:	ff 33                	pushl  (%ebx)
 80491f8:	e8 83 f7 ff ff       	call   8048980 <getopt@plt>
 80491fd:	83 c4 10             	add    $0x10,%esp
 8049200:	88 45 e7             	mov    %al,-0x19(%ebp)
 8049203:	80 7d e7 ff          	cmpb   $0xff,-0x19(%ebp)
 8049207:	0f 85 4f ff ff ff    	jne    804915c <main+0x6e>
 804920d:	a1 28 e1 04 08       	mov    0x804e128,%eax
 8049212:	85 c0                	test   %eax,%eax
 8049214:	75 27                	jne    804923d <main+0x14f>
 8049216:	8b 43 04             	mov    0x4(%ebx),%eax
 8049219:	8b 00                	mov    (%eax),%eax
 804921b:	83 ec 08             	sub    $0x8,%esp
 804921e:	50                   	push   %eax
 804921f:	68 bc a5 04 08       	push   $0x804a5bc
 8049224:	e8 17 f6 ff ff       	call   8048840 <printf@plt>
 8049229:	83 c4 10             	add    $0x10,%esp
 804922c:	8b 43 04             	mov    0x4(%ebx),%eax
 804922f:	8b 00                	mov    (%eax),%eax
 8049231:	83 ec 0c             	sub    $0xc,%esp
 8049234:	50                   	push   %eax
 8049235:	e8 42 fc ff ff       	call   8048e7c <usage>
 804923a:	83 c4 10             	add    $0x10,%esp
 804923d:	e8 ef 00 00 00       	call   8049331 <initialize_bomb>
 8049242:	a1 28 e1 04 08       	mov    0x804e128,%eax
 8049247:	83 ec 08             	sub    $0x8,%esp
 804924a:	50                   	push   %eax
 804924b:	68 e8 a5 04 08       	push   $0x804a5e8
 8049250:	e8 eb f5 ff ff       	call   8048840 <printf@plt>
 8049255:	83 c4 10             	add    $0x10,%esp
 8049258:	a1 38 e1 04 08       	mov    0x804e138,%eax
 804925d:	83 ec 08             	sub    $0x8,%esp
 8049260:	50                   	push   %eax
 8049261:	68 f4 a5 04 08       	push   $0x804a5f4
 8049266:	e8 d5 f5 ff ff       	call   8048840 <printf@plt>
 804926b:	83 c4 10             	add    $0x10,%esp
 804926e:	a1 38 e1 04 08       	mov    0x804e138,%eax
 8049273:	83 ec 0c             	sub    $0xc,%esp
 8049276:	50                   	push   %eax
 8049277:	e8 b4 f5 ff ff       	call   8048830 <srandom@plt>
 804927c:	83 c4 10             	add    $0x10,%esp
 804927f:	e8 8c f7 ff ff       	call   8048a10 <random@plt>
 8049284:	25 f0 0f 00 00       	and    $0xff0,%eax
 8049289:	05 00 01 00 00       	add    $0x100,%eax
 804928e:	89 45 e8             	mov    %eax,-0x18(%ebp)
 8049291:	8b 45 ec             	mov    -0x14(%ebp),%eax
 8049294:	83 ec 08             	sub    $0x8,%esp
 8049297:	6a 04                	push   $0x4
 8049299:	50                   	push   %eax
 804929a:	e8 b1 f7 ff ff       	call   8048a50 <calloc@plt>
 804929f:	83 c4 10             	add    $0x10,%esp
 80492a2:	89 45 e0             	mov    %eax,-0x20(%ebp)
 80492a5:	8b 45 e0             	mov    -0x20(%ebp),%eax
 80492a8:	c7 00 00 00 00 00    	movl   $0x0,(%eax)
 80492ae:	c7 45 f0 01 00 00 00 	movl   $0x1,-0x10(%ebp)
 80492b5:	eb 29                	jmp    80492e0 <main+0x1f2>
 80492b7:	8b 45 f0             	mov    -0x10(%ebp),%eax
 80492ba:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 80492c1:	8b 45 e0             	mov    -0x20(%ebp),%eax
 80492c4:	8d 1c 02             	lea    (%edx,%eax,1),%ebx
 80492c7:	e8 44 f7 ff ff       	call   8048a10 <random@plt>
 80492cc:	25 f0 00 00 00       	and    $0xf0,%eax
 80492d1:	ba 80 00 00 00       	mov    $0x80,%edx
 80492d6:	29 c2                	sub    %eax,%edx
 80492d8:	89 d0                	mov    %edx,%eax
 80492da:	89 03                	mov    %eax,(%ebx)
 80492dc:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 80492e0:	8b 45 f0             	mov    -0x10(%ebp),%eax
 80492e3:	3b 45 ec             	cmp    -0x14(%ebp),%eax
 80492e6:	7c cf                	jl     80492b7 <main+0x1c9>
 80492e8:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 80492ef:	eb 29                	jmp    804931a <main+0x22c>
 80492f1:	8b 45 f0             	mov    -0x10(%ebp),%eax
 80492f4:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 80492fb:	8b 45 e0             	mov    -0x20(%ebp),%eax
 80492fe:	01 d0                	add    %edx,%eax
 8049300:	8b 10                	mov    (%eax),%edx
 8049302:	8b 45 e8             	mov    -0x18(%ebp),%eax
 8049305:	01 d0                	add    %edx,%eax
 8049307:	83 ec 08             	sub    $0x8,%esp
 804930a:	50                   	push   %eax
 804930b:	ff 75 f4             	pushl  -0xc(%ebp)
 804930e:	e8 06 fd ff ff       	call   8049019 <launcher>
 8049313:	83 c4 10             	add    $0x10,%esp
 8049316:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 804931a:	8b 45 f0             	mov    -0x10(%ebp),%eax
 804931d:	3b 45 ec             	cmp    -0x14(%ebp),%eax
 8049320:	7c cf                	jl     80492f1 <main+0x203>
 8049322:	b8 00 00 00 00       	mov    $0x0,%eax
 8049327:	8d 65 f8             	lea    -0x8(%ebp),%esp
 804932a:	59                   	pop    %ecx
 804932b:	5b                   	pop    %ebx
 804932c:	5d                   	pop    %ebp
 804932d:	8d 61 fc             	lea    -0x4(%ecx),%esp
 8049330:	c3                   	ret    

08049331 <initialize_bomb>:
 8049331:	55                   	push   %ebp
 8049332:	89 e5                	mov    %esp,%ebp
 8049334:	81 ec 18 24 00 00    	sub    $0x2418,%esp
 804933a:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 8049341:	a1 30 e1 04 08       	mov    0x804e130,%eax
 8049346:	85 c0                	test   %eax,%eax
 8049348:	74 0d                	je     8049357 <initialize_bomb+0x26>
 804934a:	83 ec 0c             	sub    $0xc,%esp
 804934d:	6a ff                	push   $0xffffffff
 804934f:	e8 dd 0b 00 00       	call   8049f31 <init_timeout>
 8049354:	83 c4 10             	add    $0x10,%esp
 8049357:	a1 2c e1 04 08       	mov    0x804e12c,%eax
 804935c:	85 c0                	test   %eax,%eax
 804935e:	0f 84 10 01 00 00    	je     8049474 <initialize_bomb+0x143>
 8049364:	83 ec 08             	sub    $0x8,%esp
 8049367:	68 00 04 00 00       	push   $0x400
 804936c:	8d 85 f0 fb ff ff    	lea    -0x410(%ebp),%eax
 8049372:	50                   	push   %eax
 8049373:	e8 88 f5 ff ff       	call   8048900 <gethostname@plt>
 8049378:	83 c4 10             	add    $0x10,%esp
 804937b:	85 c0                	test   %eax,%eax
 804937d:	74 1a                	je     8049399 <initialize_bomb+0x68>
 804937f:	83 ec 0c             	sub    $0xc,%esp
 8049382:	68 9c a6 04 08       	push   $0x804a69c
 8049387:	e8 84 f5 ff ff       	call   8048910 <puts@plt>
 804938c:	83 c4 10             	add    $0x10,%esp
 804938f:	83 ec 0c             	sub    $0xc,%esp
 8049392:	6a 08                	push   $0x8
 8049394:	e8 87 f5 ff ff       	call   8048920 <exit@plt>
 8049399:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 80493a0:	eb 2e                	jmp    80493d0 <initialize_bomb+0x9f>
 80493a2:	8b 45 f4             	mov    -0xc(%ebp),%eax
 80493a5:	8b 04 85 c0 d0 04 08 	mov    0x804d0c0(,%eax,4),%eax
 80493ac:	83 ec 08             	sub    $0x8,%esp
 80493af:	8d 95 f0 fb ff ff    	lea    -0x410(%ebp),%edx
 80493b5:	52                   	push   %edx
 80493b6:	50                   	push   %eax
 80493b7:	e8 d4 f5 ff ff       	call   8048990 <strcasecmp@plt>
 80493bc:	83 c4 10             	add    $0x10,%esp
 80493bf:	85 c0                	test   %eax,%eax
 80493c1:	75 09                	jne    80493cc <initialize_bomb+0x9b>
 80493c3:	c7 45 f0 01 00 00 00 	movl   $0x1,-0x10(%ebp)
 80493ca:	eb 12                	jmp    80493de <initialize_bomb+0xad>
 80493cc:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 80493d0:	8b 45 f4             	mov    -0xc(%ebp),%eax
 80493d3:	8b 04 85 c0 d0 04 08 	mov    0x804d0c0(,%eax,4),%eax
 80493da:	85 c0                	test   %eax,%eax
 80493dc:	75 c4                	jne    80493a2 <initialize_bomb+0x71>
 80493de:	c7 45 f0 01 00 00 00 	movl   $0x1,-0x10(%ebp)
 80493e5:	83 7d f0 00          	cmpl   $0x0,-0x10(%ebp)
 80493e9:	75 52                	jne    804943d <initialize_bomb+0x10c>
 80493eb:	83 ec 08             	sub    $0x8,%esp
 80493ee:	8d 85 f0 fb ff ff    	lea    -0x410(%ebp),%eax
 80493f4:	50                   	push   %eax
 80493f5:	68 d4 a6 04 08       	push   $0x804a6d4
 80493fa:	e8 41 f4 ff ff       	call   8048840 <printf@plt>
 80493ff:	83 c4 10             	add    $0x10,%esp
 8049402:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 8049409:	eb 1a                	jmp    8049425 <initialize_bomb+0xf4>
 804940b:	8b 45 f4             	mov    -0xc(%ebp),%eax
 804940e:	8b 04 85 c0 d0 04 08 	mov    0x804d0c0(,%eax,4),%eax
 8049415:	83 ec 0c             	sub    $0xc,%esp
 8049418:	50                   	push   %eax
 8049419:	e8 f2 f4 ff ff       	call   8048910 <puts@plt>
 804941e:	83 c4 10             	add    $0x10,%esp
 8049421:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 8049425:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8049428:	8b 04 85 c0 d0 04 08 	mov    0x804d0c0(,%eax,4),%eax
 804942f:	85 c0                	test   %eax,%eax
 8049431:	75 d8                	jne    804940b <initialize_bomb+0xda>
 8049433:	83 ec 0c             	sub    $0xc,%esp
 8049436:	6a 08                	push   $0x8
 8049438:	e8 e3 f4 ff ff       	call   8048920 <exit@plt>
 804943d:	83 ec 0c             	sub    $0xc,%esp
 8049440:	8d 85 f0 db ff ff    	lea    -0x2410(%ebp),%eax
 8049446:	50                   	push   %eax
 8049447:	e8 24 0b 00 00       	call   8049f70 <init_driver>
 804944c:	83 c4 10             	add    $0x10,%esp
 804944f:	85 c0                	test   %eax,%eax
 8049451:	79 21                	jns    8049474 <initialize_bomb+0x143>
 8049453:	83 ec 08             	sub    $0x8,%esp
 8049456:	8d 85 f0 db ff ff    	lea    -0x2410(%ebp),%eax
 804945c:	50                   	push   %eax
 804945d:	68 0f a7 04 08       	push   $0x804a70f
 8049462:	e8 d9 f3 ff ff       	call   8048840 <printf@plt>
 8049467:	83 c4 10             	add    $0x10,%esp
 804946a:	83 ec 0c             	sub    $0xc,%esp
 804946d:	6a 08                	push   $0x8
 804946f:	e8 ac f4 ff ff       	call   8048920 <exit@plt>
 8049474:	90                   	nop
 8049475:	c9                   	leave  
 8049476:	c3                   	ret    

08049477 <validate>:
 8049477:	55                   	push   %ebp
 8049478:	89 e5                	mov    %esp,%ebp
 804947a:	81 ec 18 40 00 00    	sub    $0x4018,%esp
 8049480:	a1 28 e1 04 08       	mov    0x804e128,%eax
 8049485:	85 c0                	test   %eax,%eax
 8049487:	75 15                	jne    804949e <validate+0x27>
 8049489:	83 ec 0c             	sub    $0xc,%esp
 804948c:	68 24 a7 04 08       	push   $0x804a724
 8049491:	e8 7a f4 ff ff       	call   8048910 <puts@plt>
 8049496:	83 c4 10             	add    $0x10,%esp
 8049499:	e9 36 01 00 00       	jmp    80495d4 <validate+0x15d>
 804949e:	83 7d 08 00          	cmpl   $0x0,0x8(%ebp)
 80494a2:	78 06                	js     80494aa <validate+0x33>
 80494a4:	83 7d 08 04          	cmpl   $0x4,0x8(%ebp)
 80494a8:	7e 15                	jle    80494bf <validate+0x48>
 80494aa:	83 ec 0c             	sub    $0xc,%esp
 80494ad:	68 50 a7 04 08       	push   $0x804a750
 80494b2:	e8 59 f4 ff ff       	call   8048910 <puts@plt>
 80494b7:	83 c4 10             	add    $0x10,%esp
 80494ba:	e9 15 01 00 00       	jmp    80495d4 <validate+0x15d>
 80494bf:	c7 05 3c e1 04 08 01 	movl   $0x1,0x804e13c
 80494c6:	00 00 00 
 80494c9:	8b 45 08             	mov    0x8(%ebp),%eax
 80494cc:	8b 04 85 c0 e0 04 08 	mov    0x804e0c0(,%eax,4),%eax
 80494d3:	8d 50 ff             	lea    -0x1(%eax),%edx
 80494d6:	8b 45 08             	mov    0x8(%ebp),%eax
 80494d9:	89 14 85 c0 e0 04 08 	mov    %edx,0x804e0c0(,%eax,4)
 80494e0:	8b 45 08             	mov    0x8(%ebp),%eax
 80494e3:	8b 04 85 c0 e0 04 08 	mov    0x804e0c0(,%eax,4),%eax
 80494ea:	85 c0                	test   %eax,%eax
 80494ec:	7e 15                	jle    8049503 <validate+0x8c>
 80494ee:	83 ec 0c             	sub    $0xc,%esp
 80494f1:	68 76 a7 04 08       	push   $0x804a776
 80494f6:	e8 15 f4 ff ff       	call   8048910 <puts@plt>
 80494fb:	83 c4 10             	add    $0x10,%esp
 80494fe:	e9 d1 00 00 00       	jmp    80495d4 <validate+0x15d>
 8049503:	83 ec 0c             	sub    $0xc,%esp
 8049506:	68 81 a7 04 08       	push   $0x804a781
 804950b:	e8 00 f4 ff ff       	call   8048910 <puts@plt>
 8049510:	83 c4 10             	add    $0x10,%esp
 8049513:	a1 2c e1 04 08       	mov    0x804e12c,%eax
 8049518:	85 c0                	test   %eax,%eax
 804951a:	0f 84 a4 00 00 00    	je     80495c4 <validate+0x14d>
 8049520:	83 ec 0c             	sub    $0xc,%esp
 8049523:	68 80 e1 04 08       	push   $0x804e180
 8049528:	e8 23 f4 ff ff       	call   8048950 <strlen@plt>
 804952d:	83 c4 10             	add    $0x10,%esp
 8049530:	83 c0 20             	add    $0x20,%eax
 8049533:	3d 00 20 00 00       	cmp    $0x2000,%eax
 8049538:	76 15                	jbe    804954f <validate+0xd8>
 804953a:	83 ec 0c             	sub    $0xc,%esp
 804953d:	68 88 a7 04 08       	push   $0x804a788
 8049542:	e8 c9 f3 ff ff       	call   8048910 <puts@plt>
 8049547:	83 c4 10             	add    $0x10,%esp
 804954a:	e9 85 00 00 00       	jmp    80495d4 <validate+0x15d>
 804954f:	a1 38 e1 04 08       	mov    0x804e138,%eax
 8049554:	83 ec 0c             	sub    $0xc,%esp
 8049557:	68 80 e1 04 08       	push   $0x804e180
 804955c:	50                   	push   %eax
 804955d:	ff 75 08             	pushl  0x8(%ebp)
 8049560:	68 bf a7 04 08       	push   $0x804a7bf
 8049565:	8d 85 f4 df ff ff    	lea    -0x200c(%ebp),%eax
 804956b:	50                   	push   %eax
 804956c:	e8 7f f4 ff ff       	call   80489f0 <sprintf@plt>
 8049571:	83 c4 20             	add    $0x20,%esp
 8049574:	a1 28 e1 04 08       	mov    0x804e128,%eax
 8049579:	8d 95 f4 bf ff ff    	lea    -0x400c(%ebp),%edx
 804957f:	52                   	push   %edx
 8049580:	6a 00                	push   $0x0
 8049582:	8d 95 f4 df ff ff    	lea    -0x200c(%ebp),%edx
 8049588:	52                   	push   %edx
 8049589:	50                   	push   %eax
 804958a:	e8 87 0b 00 00       	call   804a116 <driver_post>
 804958f:	83 c4 10             	add    $0x10,%esp
 8049592:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8049595:	83 7d f4 00          	cmpl   $0x0,-0xc(%ebp)
 8049599:	75 12                	jne    80495ad <validate+0x136>
 804959b:	83 ec 0c             	sub    $0xc,%esp
 804959e:	68 c8 a7 04 08       	push   $0x804a7c8
 80495a3:	e8 68 f3 ff ff       	call   8048910 <puts@plt>
 80495a8:	83 c4 10             	add    $0x10,%esp
 80495ab:	eb 17                	jmp    80495c4 <validate+0x14d>
 80495ad:	83 ec 08             	sub    $0x8,%esp
 80495b0:	8d 85 f4 bf ff ff    	lea    -0x400c(%ebp),%eax
 80495b6:	50                   	push   %eax
 80495b7:	68 f8 a7 04 08       	push   $0x804a7f8
 80495bc:	e8 7f f2 ff ff       	call   8048840 <printf@plt>
 80495c1:	83 c4 10             	add    $0x10,%esp
 80495c4:	83 ec 0c             	sub    $0xc,%esp
 80495c7:	68 36 a8 04 08       	push   $0x804a836
 80495cc:	e8 3f f3 ff ff       	call   8048910 <puts@plt>
 80495d1:	83 c4 10             	add    $0x10,%esp
 80495d4:	c9                   	leave  
 80495d5:	c3                   	ret    

080495d6 <sigalrm_handler>:
 80495d6:	55                   	push   %ebp
 80495d7:	89 e5                	mov    %esp,%ebp
 80495d9:	83 ec 08             	sub    $0x8,%esp
 80495dc:	83 ec 08             	sub    $0x8,%esp
 80495df:	6a 05                	push   $0x5
 80495e1:	68 40 a8 04 08       	push   $0x804a840
 80495e6:	e8 55 f2 ff ff       	call   8048840 <printf@plt>
 80495eb:	83 c4 10             	add    $0x10,%esp
 80495ee:	83 ec 0c             	sub    $0xc,%esp
 80495f1:	6a 01                	push   $0x1
 80495f3:	e8 28 f3 ff ff       	call   8048920 <exit@plt>

080495f8 <rio_readinitb>:
 80495f8:	55                   	push   %ebp
 80495f9:	89 e5                	mov    %esp,%ebp
 80495fb:	8b 45 08             	mov    0x8(%ebp),%eax
 80495fe:	8b 55 0c             	mov    0xc(%ebp),%edx
 8049601:	89 10                	mov    %edx,(%eax)
 8049603:	8b 45 08             	mov    0x8(%ebp),%eax
 8049606:	c7 40 04 00 00 00 00 	movl   $0x0,0x4(%eax)
 804960d:	8b 45 08             	mov    0x8(%ebp),%eax
 8049610:	8d 50 0c             	lea    0xc(%eax),%edx
 8049613:	8b 45 08             	mov    0x8(%ebp),%eax
 8049616:	89 50 08             	mov    %edx,0x8(%eax)
 8049619:	90                   	nop
 804961a:	5d                   	pop    %ebp
 804961b:	c3                   	ret    

0804961c <rio_read>:
 804961c:	55                   	push   %ebp
 804961d:	89 e5                	mov    %esp,%ebp
 804961f:	83 ec 18             	sub    $0x18,%esp
 8049622:	eb 5f                	jmp    8049683 <rio_read+0x67>
 8049624:	8b 45 08             	mov    0x8(%ebp),%eax
 8049627:	8d 50 0c             	lea    0xc(%eax),%edx
 804962a:	8b 45 08             	mov    0x8(%ebp),%eax
 804962d:	8b 00                	mov    (%eax),%eax
 804962f:	83 ec 04             	sub    $0x4,%esp
 8049632:	68 00 20 00 00       	push   $0x2000
 8049637:	52                   	push   %edx
 8049638:	50                   	push   %eax
 8049639:	e8 e2 f1 ff ff       	call   8048820 <read@plt>
 804963e:	83 c4 10             	add    $0x10,%esp
 8049641:	89 c2                	mov    %eax,%edx
 8049643:	8b 45 08             	mov    0x8(%ebp),%eax
 8049646:	89 50 04             	mov    %edx,0x4(%eax)
 8049649:	8b 45 08             	mov    0x8(%ebp),%eax
 804964c:	8b 40 04             	mov    0x4(%eax),%eax
 804964f:	85 c0                	test   %eax,%eax
 8049651:	79 13                	jns    8049666 <rio_read+0x4a>
 8049653:	e8 68 f3 ff ff       	call   80489c0 <__errno_location@plt>
 8049658:	8b 00                	mov    (%eax),%eax
 804965a:	83 f8 04             	cmp    $0x4,%eax
 804965d:	74 24                	je     8049683 <rio_read+0x67>
 804965f:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049664:	eb 7f                	jmp    80496e5 <rio_read+0xc9>
 8049666:	8b 45 08             	mov    0x8(%ebp),%eax
 8049669:	8b 40 04             	mov    0x4(%eax),%eax
 804966c:	85 c0                	test   %eax,%eax
 804966e:	75 07                	jne    8049677 <rio_read+0x5b>
 8049670:	b8 00 00 00 00       	mov    $0x0,%eax
 8049675:	eb 6e                	jmp    80496e5 <rio_read+0xc9>
 8049677:	8b 45 08             	mov    0x8(%ebp),%eax
 804967a:	8d 50 0c             	lea    0xc(%eax),%edx
 804967d:	8b 45 08             	mov    0x8(%ebp),%eax
 8049680:	89 50 08             	mov    %edx,0x8(%eax)
 8049683:	8b 45 08             	mov    0x8(%ebp),%eax
 8049686:	8b 40 04             	mov    0x4(%eax),%eax
 8049689:	85 c0                	test   %eax,%eax
 804968b:	7e 97                	jle    8049624 <rio_read+0x8>
 804968d:	8b 45 10             	mov    0x10(%ebp),%eax
 8049690:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8049693:	8b 45 08             	mov    0x8(%ebp),%eax
 8049696:	8b 40 04             	mov    0x4(%eax),%eax
 8049699:	3b 45 10             	cmp    0x10(%ebp),%eax
 804969c:	73 09                	jae    80496a7 <rio_read+0x8b>
 804969e:	8b 45 08             	mov    0x8(%ebp),%eax
 80496a1:	8b 40 04             	mov    0x4(%eax),%eax
 80496a4:	89 45 f4             	mov    %eax,-0xc(%ebp)
 80496a7:	8b 55 f4             	mov    -0xc(%ebp),%edx
 80496aa:	8b 45 08             	mov    0x8(%ebp),%eax
 80496ad:	8b 40 08             	mov    0x8(%eax),%eax
 80496b0:	83 ec 04             	sub    $0x4,%esp
 80496b3:	52                   	push   %edx
 80496b4:	50                   	push   %eax
 80496b5:	ff 75 0c             	pushl  0xc(%ebp)
 80496b8:	e8 a3 f1 ff ff       	call   8048860 <memcpy@plt>
 80496bd:	83 c4 10             	add    $0x10,%esp
 80496c0:	8b 45 08             	mov    0x8(%ebp),%eax
 80496c3:	8b 50 08             	mov    0x8(%eax),%edx
 80496c6:	8b 45 f4             	mov    -0xc(%ebp),%eax
 80496c9:	01 c2                	add    %eax,%edx
 80496cb:	8b 45 08             	mov    0x8(%ebp),%eax
 80496ce:	89 50 08             	mov    %edx,0x8(%eax)
 80496d1:	8b 45 08             	mov    0x8(%ebp),%eax
 80496d4:	8b 40 04             	mov    0x4(%eax),%eax
 80496d7:	2b 45 f4             	sub    -0xc(%ebp),%eax
 80496da:	89 c2                	mov    %eax,%edx
 80496dc:	8b 45 08             	mov    0x8(%ebp),%eax
 80496df:	89 50 04             	mov    %edx,0x4(%eax)
 80496e2:	8b 45 f4             	mov    -0xc(%ebp),%eax
 80496e5:	c9                   	leave  
 80496e6:	c3                   	ret    

080496e7 <rio_readlineb>:
 80496e7:	55                   	push   %ebp
 80496e8:	89 e5                	mov    %esp,%ebp
 80496ea:	83 ec 18             	sub    $0x18,%esp
 80496ed:	8b 45 0c             	mov    0xc(%ebp),%eax
 80496f0:	89 45 f0             	mov    %eax,-0x10(%ebp)
 80496f3:	c7 45 f4 01 00 00 00 	movl   $0x1,-0xc(%ebp)
 80496fa:	eb 54                	jmp    8049750 <rio_readlineb+0x69>
 80496fc:	83 ec 04             	sub    $0x4,%esp
 80496ff:	6a 01                	push   $0x1
 8049701:	8d 45 eb             	lea    -0x15(%ebp),%eax
 8049704:	50                   	push   %eax
 8049705:	ff 75 08             	pushl  0x8(%ebp)
 8049708:	e8 0f ff ff ff       	call   804961c <rio_read>
 804970d:	83 c4 10             	add    $0x10,%esp
 8049710:	89 45 ec             	mov    %eax,-0x14(%ebp)
 8049713:	83 7d ec 01          	cmpl   $0x1,-0x14(%ebp)
 8049717:	75 19                	jne    8049732 <rio_readlineb+0x4b>
 8049719:	8b 45 f0             	mov    -0x10(%ebp),%eax
 804971c:	8d 50 01             	lea    0x1(%eax),%edx
 804971f:	89 55 f0             	mov    %edx,-0x10(%ebp)
 8049722:	0f b6 55 eb          	movzbl -0x15(%ebp),%edx
 8049726:	88 10                	mov    %dl,(%eax)
 8049728:	0f b6 45 eb          	movzbl -0x15(%ebp),%eax
 804972c:	3c 0a                	cmp    $0xa,%al
 804972e:	75 1c                	jne    804974c <rio_readlineb+0x65>
 8049730:	eb 29                	jmp    804975b <rio_readlineb+0x74>
 8049732:	83 7d ec 00          	cmpl   $0x0,-0x14(%ebp)
 8049736:	75 0d                	jne    8049745 <rio_readlineb+0x5e>
 8049738:	83 7d f4 01          	cmpl   $0x1,-0xc(%ebp)
 804973c:	75 1c                	jne    804975a <rio_readlineb+0x73>
 804973e:	b8 00 00 00 00       	mov    $0x0,%eax
 8049743:	eb 1f                	jmp    8049764 <rio_readlineb+0x7d>
 8049745:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 804974a:	eb 18                	jmp    8049764 <rio_readlineb+0x7d>
 804974c:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 8049750:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8049753:	3b 45 10             	cmp    0x10(%ebp),%eax
 8049756:	72 a4                	jb     80496fc <rio_readlineb+0x15>
 8049758:	eb 01                	jmp    804975b <rio_readlineb+0x74>
 804975a:	90                   	nop
 804975b:	8b 45 f0             	mov    -0x10(%ebp),%eax
 804975e:	c6 00 00             	movb   $0x0,(%eax)
 8049761:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8049764:	c9                   	leave  
 8049765:	c3                   	ret    

08049766 <rio_writen>:
 8049766:	55                   	push   %ebp
 8049767:	89 e5                	mov    %esp,%ebp
 8049769:	83 ec 18             	sub    $0x18,%esp
 804976c:	8b 45 10             	mov    0x10(%ebp),%eax
 804976f:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8049772:	8b 45 0c             	mov    0xc(%ebp),%eax
 8049775:	89 45 ec             	mov    %eax,-0x14(%ebp)
 8049778:	eb 45                	jmp    80497bf <rio_writen+0x59>
 804977a:	83 ec 04             	sub    $0x4,%esp
 804977d:	ff 75 f4             	pushl  -0xc(%ebp)
 8049780:	ff 75 ec             	pushl  -0x14(%ebp)
 8049783:	ff 75 08             	pushl  0x8(%ebp)
 8049786:	e8 e5 f1 ff ff       	call   8048970 <write@plt>
 804978b:	83 c4 10             	add    $0x10,%esp
 804978e:	89 45 f0             	mov    %eax,-0x10(%ebp)
 8049791:	83 7d f0 00          	cmpl   $0x0,-0x10(%ebp)
 8049795:	7f 1c                	jg     80497b3 <rio_writen+0x4d>
 8049797:	e8 24 f2 ff ff       	call   80489c0 <__errno_location@plt>
 804979c:	8b 00                	mov    (%eax),%eax
 804979e:	83 f8 04             	cmp    $0x4,%eax
 80497a1:	75 09                	jne    80497ac <rio_writen+0x46>
 80497a3:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 80497aa:	eb 07                	jmp    80497b3 <rio_writen+0x4d>
 80497ac:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 80497b1:	eb 15                	jmp    80497c8 <rio_writen+0x62>
 80497b3:	8b 45 f0             	mov    -0x10(%ebp),%eax
 80497b6:	29 45 f4             	sub    %eax,-0xc(%ebp)
 80497b9:	8b 45 f0             	mov    -0x10(%ebp),%eax
 80497bc:	01 45 ec             	add    %eax,-0x14(%ebp)
 80497bf:	83 7d f4 00          	cmpl   $0x0,-0xc(%ebp)
 80497c3:	75 b5                	jne    804977a <rio_writen+0x14>
 80497c5:	8b 45 10             	mov    0x10(%ebp),%eax
 80497c8:	c9                   	leave  
 80497c9:	c3                   	ret    

080497ca <urlencode>:
 80497ca:	55                   	push   %ebp
 80497cb:	89 e5                	mov    %esp,%ebp
 80497cd:	83 ec 18             	sub    $0x18,%esp
 80497d0:	83 ec 0c             	sub    $0xc,%esp
 80497d3:	ff 75 08             	pushl  0x8(%ebp)
 80497d6:	e8 75 f1 ff ff       	call   8048950 <strlen@plt>
 80497db:	83 c4 10             	add    $0x10,%esp
 80497de:	89 45 f4             	mov    %eax,-0xc(%ebp)
 80497e1:	e9 08 01 00 00       	jmp    80498ee <urlencode+0x124>
 80497e6:	8b 45 08             	mov    0x8(%ebp),%eax
 80497e9:	0f b6 00             	movzbl (%eax),%eax
 80497ec:	3c 2a                	cmp    $0x2a,%al
 80497ee:	74 5a                	je     804984a <urlencode+0x80>
 80497f0:	8b 45 08             	mov    0x8(%ebp),%eax
 80497f3:	0f b6 00             	movzbl (%eax),%eax
 80497f6:	3c 2d                	cmp    $0x2d,%al
 80497f8:	74 50                	je     804984a <urlencode+0x80>
 80497fa:	8b 45 08             	mov    0x8(%ebp),%eax
 80497fd:	0f b6 00             	movzbl (%eax),%eax
 8049800:	3c 2e                	cmp    $0x2e,%al
 8049802:	74 46                	je     804984a <urlencode+0x80>
 8049804:	8b 45 08             	mov    0x8(%ebp),%eax
 8049807:	0f b6 00             	movzbl (%eax),%eax
 804980a:	3c 5f                	cmp    $0x5f,%al
 804980c:	74 3c                	je     804984a <urlencode+0x80>
 804980e:	8b 45 08             	mov    0x8(%ebp),%eax
 8049811:	0f b6 00             	movzbl (%eax),%eax
 8049814:	3c 2f                	cmp    $0x2f,%al
 8049816:	76 0a                	jbe    8049822 <urlencode+0x58>
 8049818:	8b 45 08             	mov    0x8(%ebp),%eax
 804981b:	0f b6 00             	movzbl (%eax),%eax
 804981e:	3c 39                	cmp    $0x39,%al
 8049820:	76 28                	jbe    804984a <urlencode+0x80>
 8049822:	8b 45 08             	mov    0x8(%ebp),%eax
 8049825:	0f b6 00             	movzbl (%eax),%eax
 8049828:	3c 40                	cmp    $0x40,%al
 804982a:	76 0a                	jbe    8049836 <urlencode+0x6c>
 804982c:	8b 45 08             	mov    0x8(%ebp),%eax
 804982f:	0f b6 00             	movzbl (%eax),%eax
 8049832:	3c 5a                	cmp    $0x5a,%al
 8049834:	76 14                	jbe    804984a <urlencode+0x80>
 8049836:	8b 45 08             	mov    0x8(%ebp),%eax
 8049839:	0f b6 00             	movzbl (%eax),%eax
 804983c:	3c 60                	cmp    $0x60,%al
 804983e:	76 20                	jbe    8049860 <urlencode+0x96>
 8049840:	8b 45 08             	mov    0x8(%ebp),%eax
 8049843:	0f b6 00             	movzbl (%eax),%eax
 8049846:	3c 7a                	cmp    $0x7a,%al
 8049848:	77 16                	ja     8049860 <urlencode+0x96>
 804984a:	8b 45 0c             	mov    0xc(%ebp),%eax
 804984d:	8d 50 01             	lea    0x1(%eax),%edx
 8049850:	89 55 0c             	mov    %edx,0xc(%ebp)
 8049853:	8b 55 08             	mov    0x8(%ebp),%edx
 8049856:	0f b6 12             	movzbl (%edx),%edx
 8049859:	88 10                	mov    %dl,(%eax)
 804985b:	e9 8a 00 00 00       	jmp    80498ea <urlencode+0x120>
 8049860:	8b 45 08             	mov    0x8(%ebp),%eax
 8049863:	0f b6 00             	movzbl (%eax),%eax
 8049866:	3c 20                	cmp    $0x20,%al
 8049868:	75 0e                	jne    8049878 <urlencode+0xae>
 804986a:	8b 45 0c             	mov    0xc(%ebp),%eax
 804986d:	8d 50 01             	lea    0x1(%eax),%edx
 8049870:	89 55 0c             	mov    %edx,0xc(%ebp)
 8049873:	c6 00 2b             	movb   $0x2b,(%eax)
 8049876:	eb 72                	jmp    80498ea <urlencode+0x120>
 8049878:	8b 45 08             	mov    0x8(%ebp),%eax
 804987b:	0f b6 00             	movzbl (%eax),%eax
 804987e:	3c 1f                	cmp    $0x1f,%al
 8049880:	76 0a                	jbe    804988c <urlencode+0xc2>
 8049882:	8b 45 08             	mov    0x8(%ebp),%eax
 8049885:	0f b6 00             	movzbl (%eax),%eax
 8049888:	84 c0                	test   %al,%al
 804988a:	79 0a                	jns    8049896 <urlencode+0xcc>
 804988c:	8b 45 08             	mov    0x8(%ebp),%eax
 804988f:	0f b6 00             	movzbl (%eax),%eax
 8049892:	3c 09                	cmp    $0x9,%al
 8049894:	75 4d                	jne    80498e3 <urlencode+0x119>
 8049896:	8b 45 08             	mov    0x8(%ebp),%eax
 8049899:	0f b6 00             	movzbl (%eax),%eax
 804989c:	0f b6 c0             	movzbl %al,%eax
 804989f:	83 ec 04             	sub    $0x4,%esp
 80498a2:	50                   	push   %eax
 80498a3:	68 64 a8 04 08       	push   $0x804a864
 80498a8:	8d 45 ec             	lea    -0x14(%ebp),%eax
 80498ab:	50                   	push   %eax
 80498ac:	e8 3f f1 ff ff       	call   80489f0 <sprintf@plt>
 80498b1:	83 c4 10             	add    $0x10,%esp
 80498b4:	8b 45 0c             	mov    0xc(%ebp),%eax
 80498b7:	8d 50 01             	lea    0x1(%eax),%edx
 80498ba:	89 55 0c             	mov    %edx,0xc(%ebp)
 80498bd:	0f b6 55 ec          	movzbl -0x14(%ebp),%edx
 80498c1:	88 10                	mov    %dl,(%eax)
 80498c3:	8b 45 0c             	mov    0xc(%ebp),%eax
 80498c6:	8d 50 01             	lea    0x1(%eax),%edx
 80498c9:	89 55 0c             	mov    %edx,0xc(%ebp)
 80498cc:	0f b6 55 ed          	movzbl -0x13(%ebp),%edx
 80498d0:	88 10                	mov    %dl,(%eax)
 80498d2:	8b 45 0c             	mov    0xc(%ebp),%eax
 80498d5:	8d 50 01             	lea    0x1(%eax),%edx
 80498d8:	89 55 0c             	mov    %edx,0xc(%ebp)
 80498db:	0f b6 55 ee          	movzbl -0x12(%ebp),%edx
 80498df:	88 10                	mov    %dl,(%eax)
 80498e1:	eb 07                	jmp    80498ea <urlencode+0x120>
 80498e3:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 80498e8:	eb 1a                	jmp    8049904 <urlencode+0x13a>
 80498ea:	83 45 08 01          	addl   $0x1,0x8(%ebp)
 80498ee:	8b 45 f4             	mov    -0xc(%ebp),%eax
 80498f1:	8d 50 ff             	lea    -0x1(%eax),%edx
 80498f4:	89 55 f4             	mov    %edx,-0xc(%ebp)
 80498f7:	85 c0                	test   %eax,%eax
 80498f9:	0f 85 e7 fe ff ff    	jne    80497e6 <urlencode+0x1c>
 80498ff:	b8 00 00 00 00       	mov    $0x0,%eax
 8049904:	c9                   	leave  
 8049905:	c3                   	ret    

08049906 <submitr>:
 8049906:	55                   	push   %ebp
 8049907:	89 e5                	mov    %esp,%ebp
 8049909:	57                   	push   %edi
 804990a:	56                   	push   %esi
 804990b:	53                   	push   %ebx
 804990c:	81 ec 3c a0 00 00    	sub    $0xa03c,%esp
 8049912:	c7 85 b8 7f ff ff 00 	movl   $0x0,-0x8048(%ebp)
 8049919:	00 00 00 
 804991c:	83 ec 04             	sub    $0x4,%esp
 804991f:	6a 00                	push   $0x0
 8049921:	6a 01                	push   $0x1
 8049923:	6a 02                	push   $0x2
 8049925:	e8 d6 f0 ff ff       	call   8048a00 <socket@plt>
 804992a:	83 c4 10             	add    $0x10,%esp
 804992d:	89 45 e4             	mov    %eax,-0x1c(%ebp)
 8049930:	83 7d e4 00          	cmpl   $0x0,-0x1c(%ebp)
 8049934:	79 51                	jns    8049987 <submitr+0x81>
 8049936:	8b 45 20             	mov    0x20(%ebp),%eax
 8049939:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 804993f:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
 8049946:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
 804994d:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
 8049954:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
 804995b:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
 8049962:	c7 40 18 63 72 65 61 	movl   $0x61657263,0x18(%eax)
 8049969:	c7 40 1c 74 65 20 73 	movl   $0x73206574,0x1c(%eax)
 8049970:	c7 40 20 6f 63 6b 65 	movl   $0x656b636f,0x20(%eax)
 8049977:	66 c7 40 24 74 00    	movw   $0x74,0x24(%eax)
 804997d:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049982:	e9 a2 05 00 00       	jmp    8049f29 <submitr+0x623>
 8049987:	83 ec 0c             	sub    $0xc,%esp
 804998a:	ff 75 08             	pushl  0x8(%ebp)
 804998d:	e8 8e f0 ff ff       	call   8048a20 <gethostbyname@plt>
 8049992:	83 c4 10             	add    $0x10,%esp
 8049995:	89 45 e0             	mov    %eax,-0x20(%ebp)
 8049998:	83 7d e0 00          	cmpl   $0x0,-0x20(%ebp)
 804999c:	75 2e                	jne    80499cc <submitr+0xc6>
 804999e:	83 ec 04             	sub    $0x4,%esp
 80499a1:	ff 75 08             	pushl  0x8(%ebp)
 80499a4:	68 6c a8 04 08       	push   $0x804a86c
 80499a9:	ff 75 20             	pushl  0x20(%ebp)
 80499ac:	e8 3f f0 ff ff       	call   80489f0 <sprintf@plt>
 80499b1:	83 c4 10             	add    $0x10,%esp
 80499b4:	83 ec 0c             	sub    $0xc,%esp
 80499b7:	ff 75 e4             	pushl  -0x1c(%ebp)
 80499ba:	e8 81 f0 ff ff       	call   8048a40 <close@plt>
 80499bf:	83 c4 10             	add    $0x10,%esp
 80499c2:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 80499c7:	e9 5d 05 00 00       	jmp    8049f29 <submitr+0x623>
 80499cc:	83 ec 08             	sub    $0x8,%esp
 80499cf:	6a 10                	push   $0x10
 80499d1:	8d 45 c8             	lea    -0x38(%ebp),%eax
 80499d4:	50                   	push   %eax
 80499d5:	e8 96 ee ff ff       	call   8048870 <bzero@plt>
 80499da:	83 c4 10             	add    $0x10,%esp
 80499dd:	66 c7 45 c8 02 00    	movw   $0x2,-0x38(%ebp)
 80499e3:	8b 45 e0             	mov    -0x20(%ebp),%eax
 80499e6:	8b 40 0c             	mov    0xc(%eax),%eax
 80499e9:	89 c2                	mov    %eax,%edx
 80499eb:	8b 45 e0             	mov    -0x20(%ebp),%eax
 80499ee:	8b 40 10             	mov    0x10(%eax),%eax
 80499f1:	8b 00                	mov    (%eax),%eax
 80499f3:	83 ec 04             	sub    $0x4,%esp
 80499f6:	52                   	push   %edx
 80499f7:	8d 55 c8             	lea    -0x38(%ebp),%edx
 80499fa:	83 c2 04             	add    $0x4,%edx
 80499fd:	52                   	push   %edx
 80499fe:	50                   	push   %eax
 80499ff:	e8 cc ee ff ff       	call   80488d0 <bcopy@plt>
 8049a04:	83 c4 10             	add    $0x10,%esp
 8049a07:	8b 45 0c             	mov    0xc(%ebp),%eax
 8049a0a:	0f b7 c0             	movzwl %ax,%eax
 8049a0d:	83 ec 0c             	sub    $0xc,%esp
 8049a10:	50                   	push   %eax
 8049a11:	e8 9a ee ff ff       	call   80488b0 <htons@plt>
 8049a16:	83 c4 10             	add    $0x10,%esp
 8049a19:	66 89 45 ca          	mov    %ax,-0x36(%ebp)
 8049a1d:	83 ec 04             	sub    $0x4,%esp
 8049a20:	6a 10                	push   $0x10
 8049a22:	8d 45 c8             	lea    -0x38(%ebp),%eax
 8049a25:	50                   	push   %eax
 8049a26:	ff 75 e4             	pushl  -0x1c(%ebp)
 8049a29:	e8 02 f0 ff ff       	call   8048a30 <connect@plt>
 8049a2e:	83 c4 10             	add    $0x10,%esp
 8049a31:	85 c0                	test   %eax,%eax
 8049a33:	79 2e                	jns    8049a63 <submitr+0x15d>
 8049a35:	83 ec 04             	sub    $0x4,%esp
 8049a38:	ff 75 08             	pushl  0x8(%ebp)
 8049a3b:	68 98 a8 04 08       	push   $0x804a898
 8049a40:	ff 75 20             	pushl  0x20(%ebp)
 8049a43:	e8 a8 ef ff ff       	call   80489f0 <sprintf@plt>
 8049a48:	83 c4 10             	add    $0x10,%esp
 8049a4b:	83 ec 0c             	sub    $0xc,%esp
 8049a4e:	ff 75 e4             	pushl  -0x1c(%ebp)
 8049a51:	e8 ea ef ff ff       	call   8048a40 <close@plt>
 8049a56:	83 c4 10             	add    $0x10,%esp
 8049a59:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049a5e:	e9 c6 04 00 00       	jmp    8049f29 <submitr+0x623>
 8049a63:	83 ec 0c             	sub    $0xc,%esp
 8049a66:	ff 75 1c             	pushl  0x1c(%ebp)
 8049a69:	e8 e2 ee ff ff       	call   8048950 <strlen@plt>
 8049a6e:	83 c4 10             	add    $0x10,%esp
 8049a71:	89 45 dc             	mov    %eax,-0x24(%ebp)
 8049a74:	83 ec 0c             	sub    $0xc,%esp
 8049a77:	ff 75 10             	pushl  0x10(%ebp)
 8049a7a:	e8 d1 ee ff ff       	call   8048950 <strlen@plt>
 8049a7f:	83 c4 10             	add    $0x10,%esp
 8049a82:	89 c3                	mov    %eax,%ebx
 8049a84:	83 ec 0c             	sub    $0xc,%esp
 8049a87:	ff 75 14             	pushl  0x14(%ebp)
 8049a8a:	e8 c1 ee ff ff       	call   8048950 <strlen@plt>
 8049a8f:	83 c4 10             	add    $0x10,%esp
 8049a92:	01 c3                	add    %eax,%ebx
 8049a94:	83 ec 0c             	sub    $0xc,%esp
 8049a97:	ff 75 18             	pushl  0x18(%ebp)
 8049a9a:	e8 b1 ee ff ff       	call   8048950 <strlen@plt>
 8049a9f:	83 c4 10             	add    $0x10,%esp
 8049aa2:	8d 0c 03             	lea    (%ebx,%eax,1),%ecx
 8049aa5:	8b 55 dc             	mov    -0x24(%ebp),%edx
 8049aa8:	89 d0                	mov    %edx,%eax
 8049aaa:	01 c0                	add    %eax,%eax
 8049aac:	01 d0                	add    %edx,%eax
 8049aae:	01 c8                	add    %ecx,%eax
 8049ab0:	83 e8 80             	sub    $0xffffff80,%eax
 8049ab3:	89 45 d8             	mov    %eax,-0x28(%ebp)
 8049ab6:	81 7d d8 00 20 00 00 	cmpl   $0x2000,-0x28(%ebp)
 8049abd:	76 7c                	jbe    8049b3b <submitr+0x235>
 8049abf:	8b 45 20             	mov    0x20(%ebp),%eax
 8049ac2:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 8049ac8:	c7 40 04 72 3a 20 52 	movl   $0x52203a72,0x4(%eax)
 8049acf:	c7 40 08 65 73 75 6c 	movl   $0x6c757365,0x8(%eax)
 8049ad6:	c7 40 0c 74 20 73 74 	movl   $0x74732074,0xc(%eax)
 8049add:	c7 40 10 72 69 6e 67 	movl   $0x676e6972,0x10(%eax)
 8049ae4:	c7 40 14 20 74 6f 6f 	movl   $0x6f6f7420,0x14(%eax)
 8049aeb:	c7 40 18 20 6c 61 72 	movl   $0x72616c20,0x18(%eax)
 8049af2:	c7 40 1c 67 65 2e 20 	movl   $0x202e6567,0x1c(%eax)
 8049af9:	c7 40 20 49 6e 63 72 	movl   $0x72636e49,0x20(%eax)
 8049b00:	c7 40 24 65 61 73 65 	movl   $0x65736165,0x24(%eax)
 8049b07:	c7 40 28 20 53 55 42 	movl   $0x42555320,0x28(%eax)
 8049b0e:	c7 40 2c 4d 49 54 52 	movl   $0x5254494d,0x2c(%eax)
 8049b15:	c7 40 30 5f 4d 41 58 	movl   $0x58414d5f,0x30(%eax)
 8049b1c:	c7 40 34 42 55 46 00 	movl   $0x465542,0x34(%eax)
 8049b23:	83 ec 0c             	sub    $0xc,%esp
 8049b26:	ff 75 e4             	pushl  -0x1c(%ebp)
 8049b29:	e8 12 ef ff ff       	call   8048a40 <close@plt>
 8049b2e:	83 c4 10             	add    $0x10,%esp
 8049b31:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049b36:	e9 ee 03 00 00       	jmp    8049f29 <submitr+0x623>
 8049b3b:	83 ec 08             	sub    $0x8,%esp
 8049b3e:	68 00 20 00 00       	push   $0x2000
 8049b43:	8d 85 bc 9f ff ff    	lea    -0x6044(%ebp),%eax
 8049b49:	50                   	push   %eax
 8049b4a:	e8 21 ed ff ff       	call   8048870 <bzero@plt>
 8049b4f:	83 c4 10             	add    $0x10,%esp
 8049b52:	83 ec 08             	sub    $0x8,%esp
 8049b55:	8d 85 bc 9f ff ff    	lea    -0x6044(%ebp),%eax
 8049b5b:	50                   	push   %eax
 8049b5c:	ff 75 1c             	pushl  0x1c(%ebp)
 8049b5f:	e8 66 fc ff ff       	call   80497ca <urlencode>
 8049b64:	83 c4 10             	add    $0x10,%esp
 8049b67:	85 c0                	test   %eax,%eax
 8049b69:	79 4b                	jns    8049bb6 <submitr+0x2b0>
 8049b6b:	8b 45 20             	mov    0x20(%ebp),%eax
 8049b6e:	bb c0 a8 04 08       	mov    $0x804a8c0,%ebx
 8049b73:	ba 43 00 00 00       	mov    $0x43,%edx
 8049b78:	8b 0b                	mov    (%ebx),%ecx
 8049b7a:	89 08                	mov    %ecx,(%eax)
 8049b7c:	8b 4c 13 fc          	mov    -0x4(%ebx,%edx,1),%ecx
 8049b80:	89 4c 10 fc          	mov    %ecx,-0x4(%eax,%edx,1)
 8049b84:	8d 78 04             	lea    0x4(%eax),%edi
 8049b87:	83 e7 fc             	and    $0xfffffffc,%edi
 8049b8a:	29 f8                	sub    %edi,%eax
 8049b8c:	29 c3                	sub    %eax,%ebx
 8049b8e:	01 c2                	add    %eax,%edx
 8049b90:	83 e2 fc             	and    $0xfffffffc,%edx
 8049b93:	89 d0                	mov    %edx,%eax
 8049b95:	c1 e8 02             	shr    $0x2,%eax
 8049b98:	89 de                	mov    %ebx,%esi
 8049b9a:	89 c1                	mov    %eax,%ecx
 8049b9c:	f3 a5                	rep movsl %ds:(%esi),%es:(%edi)
 8049b9e:	83 ec 0c             	sub    $0xc,%esp
 8049ba1:	ff 75 e4             	pushl  -0x1c(%ebp)
 8049ba4:	e8 97 ee ff ff       	call   8048a40 <close@plt>
 8049ba9:	83 c4 10             	add    $0x10,%esp
 8049bac:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049bb1:	e9 73 03 00 00       	jmp    8049f29 <submitr+0x623>
 8049bb6:	83 ec 08             	sub    $0x8,%esp
 8049bb9:	8d 85 bc 9f ff ff    	lea    -0x6044(%ebp),%eax
 8049bbf:	50                   	push   %eax
 8049bc0:	ff 75 18             	pushl  0x18(%ebp)
 8049bc3:	ff 75 14             	pushl  0x14(%ebp)
 8049bc6:	ff 75 10             	pushl  0x10(%ebp)
 8049bc9:	68 04 a9 04 08       	push   $0x804a904
 8049bce:	8d 85 bc bf ff ff    	lea    -0x4044(%ebp),%eax
 8049bd4:	50                   	push   %eax
 8049bd5:	e8 16 ee ff ff       	call   80489f0 <sprintf@plt>
 8049bda:	83 c4 20             	add    $0x20,%esp
 8049bdd:	83 ec 0c             	sub    $0xc,%esp
 8049be0:	8d 85 bc bf ff ff    	lea    -0x4044(%ebp),%eax
 8049be6:	50                   	push   %eax
 8049be7:	e8 64 ed ff ff       	call   8048950 <strlen@plt>
 8049bec:	83 c4 10             	add    $0x10,%esp
 8049bef:	83 ec 04             	sub    $0x4,%esp
 8049bf2:	50                   	push   %eax
 8049bf3:	8d 85 bc bf ff ff    	lea    -0x4044(%ebp),%eax
 8049bf9:	50                   	push   %eax
 8049bfa:	ff 75 e4             	pushl  -0x1c(%ebp)
 8049bfd:	e8 64 fb ff ff       	call   8049766 <rio_writen>
 8049c02:	83 c4 10             	add    $0x10,%esp
 8049c05:	85 c0                	test   %eax,%eax
 8049c07:	79 67                	jns    8049c70 <submitr+0x36a>
 8049c09:	8b 45 20             	mov    0x20(%ebp),%eax
 8049c0c:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 8049c12:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
 8049c19:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
 8049c20:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
 8049c27:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
 8049c2e:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
 8049c35:	c7 40 18 77 72 69 74 	movl   $0x74697277,0x18(%eax)
 8049c3c:	c7 40 1c 65 20 74 6f 	movl   $0x6f742065,0x1c(%eax)
 8049c43:	c7 40 20 20 74 68 65 	movl   $0x65687420,0x20(%eax)
 8049c4a:	c7 40 24 20 73 65 72 	movl   $0x72657320,0x24(%eax)
 8049c51:	c7 40 28 76 65 72 00 	movl   $0x726576,0x28(%eax)
 8049c58:	83 ec 0c             	sub    $0xc,%esp
 8049c5b:	ff 75 e4             	pushl  -0x1c(%ebp)
 8049c5e:	e8 dd ed ff ff       	call   8048a40 <close@plt>
 8049c63:	83 c4 10             	add    $0x10,%esp
 8049c66:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049c6b:	e9 b9 02 00 00       	jmp    8049f29 <submitr+0x623>
 8049c70:	83 ec 08             	sub    $0x8,%esp
 8049c73:	ff 75 e4             	pushl  -0x1c(%ebp)
 8049c76:	8d 85 bc df ff ff    	lea    -0x2044(%ebp),%eax
 8049c7c:	50                   	push   %eax
 8049c7d:	e8 76 f9 ff ff       	call   80495f8 <rio_readinitb>
 8049c82:	83 c4 10             	add    $0x10,%esp
 8049c85:	83 ec 04             	sub    $0x4,%esp
 8049c88:	68 00 20 00 00       	push   $0x2000
 8049c8d:	8d 85 bc bf ff ff    	lea    -0x4044(%ebp),%eax
 8049c93:	50                   	push   %eax
 8049c94:	8d 85 bc df ff ff    	lea    -0x2044(%ebp),%eax
 8049c9a:	50                   	push   %eax
 8049c9b:	e8 47 fa ff ff       	call   80496e7 <rio_readlineb>
 8049ca0:	83 c4 10             	add    $0x10,%esp
 8049ca3:	85 c0                	test   %eax,%eax
 8049ca5:	7f 7b                	jg     8049d22 <submitr+0x41c>
 8049ca7:	8b 45 20             	mov    0x20(%ebp),%eax
 8049caa:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 8049cb0:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
 8049cb7:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
 8049cbe:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
 8049cc5:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
 8049ccc:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
 8049cd3:	c7 40 18 72 65 61 64 	movl   $0x64616572,0x18(%eax)
 8049cda:	c7 40 1c 20 66 69 72 	movl   $0x72696620,0x1c(%eax)
 8049ce1:	c7 40 20 73 74 20 68 	movl   $0x68207473,0x20(%eax)
 8049ce8:	c7 40 24 65 61 64 65 	movl   $0x65646165,0x24(%eax)
 8049cef:	c7 40 28 72 20 66 72 	movl   $0x72662072,0x28(%eax)
 8049cf6:	c7 40 2c 6f 6d 20 73 	movl   $0x73206d6f,0x2c(%eax)
 8049cfd:	c7 40 30 65 72 76 65 	movl   $0x65767265,0x30(%eax)
 8049d04:	66 c7 40 34 72 00    	movw   $0x72,0x34(%eax)
 8049d0a:	83 ec 0c             	sub    $0xc,%esp
 8049d0d:	ff 75 e4             	pushl  -0x1c(%ebp)
 8049d10:	e8 2b ed ff ff       	call   8048a40 <close@plt>
 8049d15:	83 c4 10             	add    $0x10,%esp
 8049d18:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049d1d:	e9 07 02 00 00       	jmp    8049f29 <submitr+0x623>
 8049d22:	83 ec 0c             	sub    $0xc,%esp
 8049d25:	8d 85 b8 5f ff ff    	lea    -0xa048(%ebp),%eax
 8049d2b:	50                   	push   %eax
 8049d2c:	8d 85 b8 7f ff ff    	lea    -0x8048(%ebp),%eax
 8049d32:	50                   	push   %eax
 8049d33:	8d 85 bc 7f ff ff    	lea    -0x8044(%ebp),%eax
 8049d39:	50                   	push   %eax
 8049d3a:	68 4e a9 04 08       	push   $0x804a94e
 8049d3f:	8d 85 bc bf ff ff    	lea    -0x4044(%ebp),%eax
 8049d45:	50                   	push   %eax
 8049d46:	e8 55 ec ff ff       	call   80489a0 <__isoc99_sscanf@plt>
 8049d4b:	83 c4 20             	add    $0x20,%esp
 8049d4e:	8b 85 b8 7f ff ff    	mov    -0x8048(%ebp),%eax
 8049d54:	3d c8 00 00 00       	cmp    $0xc8,%eax
 8049d59:	0f 84 ca 00 00 00    	je     8049e29 <submitr+0x523>
 8049d5f:	8b 85 b8 7f ff ff    	mov    -0x8048(%ebp),%eax
 8049d65:	8d 95 b8 5f ff ff    	lea    -0xa048(%ebp),%edx
 8049d6b:	52                   	push   %edx
 8049d6c:	50                   	push   %eax
 8049d6d:	68 60 a9 04 08       	push   $0x804a960
 8049d72:	ff 75 20             	pushl  0x20(%ebp)
 8049d75:	e8 76 ec ff ff       	call   80489f0 <sprintf@plt>
 8049d7a:	83 c4 10             	add    $0x10,%esp
 8049d7d:	83 ec 0c             	sub    $0xc,%esp
 8049d80:	ff 75 e4             	pushl  -0x1c(%ebp)
 8049d83:	e8 b8 ec ff ff       	call   8048a40 <close@plt>
 8049d88:	83 c4 10             	add    $0x10,%esp
 8049d8b:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049d90:	e9 94 01 00 00       	jmp    8049f29 <submitr+0x623>
 8049d95:	83 ec 04             	sub    $0x4,%esp
 8049d98:	68 00 20 00 00       	push   $0x2000
 8049d9d:	8d 85 bc bf ff ff    	lea    -0x4044(%ebp),%eax
 8049da3:	50                   	push   %eax
 8049da4:	8d 85 bc df ff ff    	lea    -0x2044(%ebp),%eax
 8049daa:	50                   	push   %eax
 8049dab:	e8 37 f9 ff ff       	call   80496e7 <rio_readlineb>
 8049db0:	83 c4 10             	add    $0x10,%esp
 8049db3:	85 c0                	test   %eax,%eax
 8049db5:	7f 72                	jg     8049e29 <submitr+0x523>
 8049db7:	8b 45 20             	mov    0x20(%ebp),%eax
 8049dba:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 8049dc0:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
 8049dc7:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
 8049dce:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
 8049dd5:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
 8049ddc:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
 8049de3:	c7 40 18 72 65 61 64 	movl   $0x64616572,0x18(%eax)
 8049dea:	c7 40 1c 20 68 65 61 	movl   $0x61656820,0x1c(%eax)
 8049df1:	c7 40 20 64 65 72 73 	movl   $0x73726564,0x20(%eax)
 8049df8:	c7 40 24 20 66 72 6f 	movl   $0x6f726620,0x24(%eax)
 8049dff:	c7 40 28 6d 20 73 65 	movl   $0x6573206d,0x28(%eax)
 8049e06:	c7 40 2c 72 76 65 72 	movl   $0x72657672,0x2c(%eax)
 8049e0d:	c6 40 30 00          	movb   $0x0,0x30(%eax)
 8049e11:	83 ec 0c             	sub    $0xc,%esp
 8049e14:	ff 75 e4             	pushl  -0x1c(%ebp)
 8049e17:	e8 24 ec ff ff       	call   8048a40 <close@plt>
 8049e1c:	83 c4 10             	add    $0x10,%esp
 8049e1f:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049e24:	e9 00 01 00 00       	jmp    8049f29 <submitr+0x623>
 8049e29:	83 ec 08             	sub    $0x8,%esp
 8049e2c:	68 8d a9 04 08       	push   $0x804a98d
 8049e31:	8d 85 bc bf ff ff    	lea    -0x4044(%ebp),%eax
 8049e37:	50                   	push   %eax
 8049e38:	e8 d3 e9 ff ff       	call   8048810 <strcmp@plt>
 8049e3d:	83 c4 10             	add    $0x10,%esp
 8049e40:	85 c0                	test   %eax,%eax
 8049e42:	0f 85 4d ff ff ff    	jne    8049d95 <submitr+0x48f>
 8049e48:	83 ec 04             	sub    $0x4,%esp
 8049e4b:	68 00 20 00 00       	push   $0x2000
 8049e50:	8d 85 bc bf ff ff    	lea    -0x4044(%ebp),%eax
 8049e56:	50                   	push   %eax
 8049e57:	8d 85 bc df ff ff    	lea    -0x2044(%ebp),%eax
 8049e5d:	50                   	push   %eax
 8049e5e:	e8 84 f8 ff ff       	call   80496e7 <rio_readlineb>
 8049e63:	83 c4 10             	add    $0x10,%esp
 8049e66:	85 c0                	test   %eax,%eax
 8049e68:	7f 79                	jg     8049ee3 <submitr+0x5dd>
 8049e6a:	8b 45 20             	mov    0x20(%ebp),%eax
 8049e6d:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 8049e73:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
 8049e7a:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
 8049e81:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
 8049e88:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
 8049e8f:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
 8049e96:	c7 40 18 72 65 61 64 	movl   $0x64616572,0x18(%eax)
 8049e9d:	c7 40 1c 20 73 74 61 	movl   $0x61747320,0x1c(%eax)
 8049ea4:	c7 40 20 74 75 73 20 	movl   $0x20737574,0x20(%eax)
 8049eab:	c7 40 24 6d 65 73 73 	movl   $0x7373656d,0x24(%eax)
 8049eb2:	c7 40 28 61 67 65 20 	movl   $0x20656761,0x28(%eax)
 8049eb9:	c7 40 2c 66 72 6f 6d 	movl   $0x6d6f7266,0x2c(%eax)
 8049ec0:	c7 40 30 20 73 65 72 	movl   $0x72657320,0x30(%eax)
 8049ec7:	c7 40 34 76 65 72 00 	movl   $0x726576,0x34(%eax)
 8049ece:	83 ec 0c             	sub    $0xc,%esp
 8049ed1:	ff 75 e4             	pushl  -0x1c(%ebp)
 8049ed4:	e8 67 eb ff ff       	call   8048a40 <close@plt>
 8049ed9:	83 c4 10             	add    $0x10,%esp
 8049edc:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049ee1:	eb 46                	jmp    8049f29 <submitr+0x623>
 8049ee3:	83 ec 08             	sub    $0x8,%esp
 8049ee6:	8d 85 bc bf ff ff    	lea    -0x4044(%ebp),%eax
 8049eec:	50                   	push   %eax
 8049eed:	ff 75 20             	pushl  0x20(%ebp)
 8049ef0:	e8 eb e9 ff ff       	call   80488e0 <strcpy@plt>
 8049ef5:	83 c4 10             	add    $0x10,%esp
 8049ef8:	83 ec 0c             	sub    $0xc,%esp
 8049efb:	ff 75 e4             	pushl  -0x1c(%ebp)
 8049efe:	e8 3d eb ff ff       	call   8048a40 <close@plt>
 8049f03:	83 c4 10             	add    $0x10,%esp
 8049f06:	83 ec 08             	sub    $0x8,%esp
 8049f09:	68 90 a9 04 08       	push   $0x804a990
 8049f0e:	ff 75 20             	pushl  0x20(%ebp)
 8049f11:	e8 fa e8 ff ff       	call   8048810 <strcmp@plt>
 8049f16:	83 c4 10             	add    $0x10,%esp
 8049f19:	85 c0                	test   %eax,%eax
 8049f1b:	75 07                	jne    8049f24 <submitr+0x61e>
 8049f1d:	b8 00 00 00 00       	mov    $0x0,%eax
 8049f22:	eb 05                	jmp    8049f29 <submitr+0x623>
 8049f24:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049f29:	8d 65 f4             	lea    -0xc(%ebp),%esp
 8049f2c:	5b                   	pop    %ebx
 8049f2d:	5e                   	pop    %esi
 8049f2e:	5f                   	pop    %edi
 8049f2f:	5d                   	pop    %ebp
 8049f30:	c3                   	ret    

08049f31 <init_timeout>:
 8049f31:	55                   	push   %ebp
 8049f32:	89 e5                	mov    %esp,%ebp
 8049f34:	83 ec 08             	sub    $0x8,%esp
 8049f37:	83 7d 08 00          	cmpl   $0x0,0x8(%ebp)
 8049f3b:	74 30                	je     8049f6d <init_timeout+0x3c>
 8049f3d:	83 7d 08 00          	cmpl   $0x0,0x8(%ebp)
 8049f41:	79 07                	jns    8049f4a <init_timeout+0x19>
 8049f43:	c7 45 08 05 00 00 00 	movl   $0x5,0x8(%ebp)
 8049f4a:	83 ec 08             	sub    $0x8,%esp
 8049f4d:	68 d6 95 04 08       	push   $0x80495d6
 8049f52:	6a 0e                	push   $0xe
 8049f54:	e8 27 e9 ff ff       	call   8048880 <signal@plt>
 8049f59:	83 c4 10             	add    $0x10,%esp
 8049f5c:	8b 45 08             	mov    0x8(%ebp),%eax
 8049f5f:	83 ec 0c             	sub    $0xc,%esp
 8049f62:	50                   	push   %eax
 8049f63:	e8 28 e9 ff ff       	call   8048890 <alarm@plt>
 8049f68:	83 c4 10             	add    $0x10,%esp
 8049f6b:	eb 01                	jmp    8049f6e <init_timeout+0x3d>
 8049f6d:	90                   	nop
 8049f6e:	c9                   	leave  
 8049f6f:	c3                   	ret    

08049f70 <init_driver>:
 8049f70:	55                   	push   %ebp
 8049f71:	89 e5                	mov    %esp,%ebp
 8049f73:	83 ec 28             	sub    $0x28,%esp
 8049f76:	c7 45 f4 93 a9 04 08 	movl   $0x804a993,-0xc(%ebp)
 8049f7d:	c7 45 f0 26 47 00 00 	movl   $0x4726,-0x10(%ebp)
 8049f84:	83 ec 08             	sub    $0x8,%esp
 8049f87:	6a 01                	push   $0x1
 8049f89:	6a 0d                	push   $0xd
 8049f8b:	e8 f0 e8 ff ff       	call   8048880 <signal@plt>
 8049f90:	83 c4 10             	add    $0x10,%esp
 8049f93:	83 ec 08             	sub    $0x8,%esp
 8049f96:	6a 01                	push   $0x1
 8049f98:	6a 1d                	push   $0x1d
 8049f9a:	e8 e1 e8 ff ff       	call   8048880 <signal@plt>
 8049f9f:	83 c4 10             	add    $0x10,%esp
 8049fa2:	83 ec 08             	sub    $0x8,%esp
 8049fa5:	6a 01                	push   $0x1
 8049fa7:	6a 1d                	push   $0x1d
 8049fa9:	e8 d2 e8 ff ff       	call   8048880 <signal@plt>
 8049fae:	83 c4 10             	add    $0x10,%esp
 8049fb1:	83 ec 04             	sub    $0x4,%esp
 8049fb4:	6a 00                	push   $0x0
 8049fb6:	6a 01                	push   $0x1
 8049fb8:	6a 02                	push   $0x2
 8049fba:	e8 41 ea ff ff       	call   8048a00 <socket@plt>
 8049fbf:	83 c4 10             	add    $0x10,%esp
 8049fc2:	89 45 ec             	mov    %eax,-0x14(%ebp)
 8049fc5:	83 7d ec 00          	cmpl   $0x0,-0x14(%ebp)
 8049fc9:	79 51                	jns    804a01c <init_driver+0xac>
 8049fcb:	8b 45 08             	mov    0x8(%ebp),%eax
 8049fce:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 8049fd4:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
 8049fdb:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
 8049fe2:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
 8049fe9:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
 8049ff0:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
 8049ff7:	c7 40 18 63 72 65 61 	movl   $0x61657263,0x18(%eax)
 8049ffe:	c7 40 1c 74 65 20 73 	movl   $0x73206574,0x1c(%eax)
 804a005:	c7 40 20 6f 63 6b 65 	movl   $0x656b636f,0x20(%eax)
 804a00c:	66 c7 40 24 74 00    	movw   $0x74,0x24(%eax)
 804a012:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 804a017:	e9 f8 00 00 00       	jmp    804a114 <init_driver+0x1a4>
 804a01c:	83 ec 0c             	sub    $0xc,%esp
 804a01f:	ff 75 f4             	pushl  -0xc(%ebp)
 804a022:	e8 f9 e9 ff ff       	call   8048a20 <gethostbyname@plt>
 804a027:	83 c4 10             	add    $0x10,%esp
 804a02a:	89 45 e8             	mov    %eax,-0x18(%ebp)
 804a02d:	83 7d e8 00          	cmpl   $0x0,-0x18(%ebp)
 804a031:	75 2e                	jne    804a061 <init_driver+0xf1>
 804a033:	83 ec 04             	sub    $0x4,%esp
 804a036:	ff 75 f4             	pushl  -0xc(%ebp)
 804a039:	68 6c a8 04 08       	push   $0x804a86c
 804a03e:	ff 75 08             	pushl  0x8(%ebp)
 804a041:	e8 aa e9 ff ff       	call   80489f0 <sprintf@plt>
 804a046:	83 c4 10             	add    $0x10,%esp
 804a049:	83 ec 0c             	sub    $0xc,%esp
 804a04c:	ff 75 ec             	pushl  -0x14(%ebp)
 804a04f:	e8 ec e9 ff ff       	call   8048a40 <close@plt>
 804a054:	83 c4 10             	add    $0x10,%esp
 804a057:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 804a05c:	e9 b3 00 00 00       	jmp    804a114 <init_driver+0x1a4>
 804a061:	83 ec 08             	sub    $0x8,%esp
 804a064:	6a 10                	push   $0x10
 804a066:	8d 45 d8             	lea    -0x28(%ebp),%eax
 804a069:	50                   	push   %eax
 804a06a:	e8 01 e8 ff ff       	call   8048870 <bzero@plt>
 804a06f:	83 c4 10             	add    $0x10,%esp
 804a072:	66 c7 45 d8 02 00    	movw   $0x2,-0x28(%ebp)
 804a078:	8b 45 e8             	mov    -0x18(%ebp),%eax
 804a07b:	8b 40 0c             	mov    0xc(%eax),%eax
 804a07e:	89 c2                	mov    %eax,%edx
 804a080:	8b 45 e8             	mov    -0x18(%ebp),%eax
 804a083:	8b 40 10             	mov    0x10(%eax),%eax
 804a086:	8b 00                	mov    (%eax),%eax
 804a088:	83 ec 04             	sub    $0x4,%esp
 804a08b:	52                   	push   %edx
 804a08c:	8d 55 d8             	lea    -0x28(%ebp),%edx
 804a08f:	83 c2 04             	add    $0x4,%edx
 804a092:	52                   	push   %edx
 804a093:	50                   	push   %eax
 804a094:	e8 37 e8 ff ff       	call   80488d0 <bcopy@plt>
 804a099:	83 c4 10             	add    $0x10,%esp
 804a09c:	8b 45 f0             	mov    -0x10(%ebp),%eax
 804a09f:	0f b7 c0             	movzwl %ax,%eax
 804a0a2:	83 ec 0c             	sub    $0xc,%esp
 804a0a5:	50                   	push   %eax
 804a0a6:	e8 05 e8 ff ff       	call   80488b0 <htons@plt>
 804a0ab:	83 c4 10             	add    $0x10,%esp
 804a0ae:	66 89 45 da          	mov    %ax,-0x26(%ebp)
 804a0b2:	83 ec 04             	sub    $0x4,%esp
 804a0b5:	6a 10                	push   $0x10
 804a0b7:	8d 45 d8             	lea    -0x28(%ebp),%eax
 804a0ba:	50                   	push   %eax
 804a0bb:	ff 75 ec             	pushl  -0x14(%ebp)
 804a0be:	e8 6d e9 ff ff       	call   8048a30 <connect@plt>
 804a0c3:	83 c4 10             	add    $0x10,%esp
 804a0c6:	85 c0                	test   %eax,%eax
 804a0c8:	79 2b                	jns    804a0f5 <init_driver+0x185>
 804a0ca:	ff 75 f0             	pushl  -0x10(%ebp)
 804a0cd:	ff 75 f4             	pushl  -0xc(%ebp)
 804a0d0:	68 a4 a9 04 08       	push   $0x804a9a4
 804a0d5:	ff 75 08             	pushl  0x8(%ebp)
 804a0d8:	e8 13 e9 ff ff       	call   80489f0 <sprintf@plt>
 804a0dd:	83 c4 10             	add    $0x10,%esp
 804a0e0:	83 ec 0c             	sub    $0xc,%esp
 804a0e3:	ff 75 ec             	pushl  -0x14(%ebp)
 804a0e6:	e8 55 e9 ff ff       	call   8048a40 <close@plt>
 804a0eb:	83 c4 10             	add    $0x10,%esp
 804a0ee:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 804a0f3:	eb 1f                	jmp    804a114 <init_driver+0x1a4>
 804a0f5:	83 ec 0c             	sub    $0xc,%esp
 804a0f8:	ff 75 ec             	pushl  -0x14(%ebp)
 804a0fb:	e8 40 e9 ff ff       	call   8048a40 <close@plt>
 804a100:	83 c4 10             	add    $0x10,%esp
 804a103:	8b 45 08             	mov    0x8(%ebp),%eax
 804a106:	66 c7 00 4f 4b       	movw   $0x4b4f,(%eax)
 804a10b:	c6 40 02 00          	movb   $0x0,0x2(%eax)
 804a10f:	b8 00 00 00 00       	mov    $0x0,%eax
 804a114:	c9                   	leave  
 804a115:	c3                   	ret    

0804a116 <driver_post>:
 804a116:	55                   	push   %ebp
 804a117:	89 e5                	mov    %esp,%ebp
 804a119:	83 ec 18             	sub    $0x18,%esp
 804a11c:	83 7d 10 00          	cmpl   $0x0,0x10(%ebp)
 804a120:	74 26                	je     804a148 <driver_post+0x32>
 804a122:	83 ec 08             	sub    $0x8,%esp
 804a125:	ff 75 0c             	pushl  0xc(%ebp)
 804a128:	68 cd a9 04 08       	push   $0x804a9cd
 804a12d:	e8 0e e7 ff ff       	call   8048840 <printf@plt>
 804a132:	83 c4 10             	add    $0x10,%esp
 804a135:	8b 45 14             	mov    0x14(%ebp),%eax
 804a138:	66 c7 00 4f 4b       	movw   $0x4b4f,(%eax)
 804a13d:	c6 40 02 00          	movb   $0x0,0x2(%eax)
 804a141:	b8 00 00 00 00       	mov    $0x0,%eax
 804a146:	eb 51                	jmp    804a199 <driver_post+0x83>
 804a148:	83 7d 08 00          	cmpl   $0x0,0x8(%ebp)
 804a14c:	74 3a                	je     804a188 <driver_post+0x72>
 804a14e:	8b 45 08             	mov    0x8(%ebp),%eax
 804a151:	0f b6 00             	movzbl (%eax),%eax
 804a154:	84 c0                	test   %al,%al
 804a156:	74 30                	je     804a188 <driver_post+0x72>
 804a158:	83 ec 04             	sub    $0x4,%esp
 804a15b:	ff 75 14             	pushl  0x14(%ebp)
 804a15e:	ff 75 0c             	pushl  0xc(%ebp)
 804a161:	68 e4 a9 04 08       	push   $0x804a9e4
 804a166:	ff 75 08             	pushl  0x8(%ebp)
 804a169:	68 eb a9 04 08       	push   $0x804a9eb
 804a16e:	68 26 47 00 00       	push   $0x4726
 804a173:	68 93 a9 04 08       	push   $0x804a993
 804a178:	e8 89 f7 ff ff       	call   8049906 <submitr>
 804a17d:	83 c4 20             	add    $0x20,%esp
 804a180:	89 45 f4             	mov    %eax,-0xc(%ebp)
 804a183:	8b 45 f4             	mov    -0xc(%ebp),%eax
 804a186:	eb 11                	jmp    804a199 <driver_post+0x83>
 804a188:	8b 45 14             	mov    0x14(%ebp),%eax
 804a18b:	66 c7 00 4f 4b       	movw   $0x4b4f,(%eax)
 804a190:	c6 40 02 00          	movb   $0x0,0x2(%eax)
 804a194:	b8 00 00 00 00       	mov    $0x0,%eax
 804a199:	c9                   	leave  
 804a19a:	c3                   	ret    

0804a19b <hash>:
 804a19b:	55                   	push   %ebp
 804a19c:	89 e5                	mov    %esp,%ebp
 804a19e:	83 ec 10             	sub    $0x10,%esp
 804a1a1:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%ebp)
 804a1a8:	eb 1a                	jmp    804a1c4 <hash+0x29>
 804a1aa:	8b 45 fc             	mov    -0x4(%ebp),%eax
 804a1ad:	6b c8 67             	imul   $0x67,%eax,%ecx
 804a1b0:	8b 45 08             	mov    0x8(%ebp),%eax
 804a1b3:	8d 50 01             	lea    0x1(%eax),%edx
 804a1b6:	89 55 08             	mov    %edx,0x8(%ebp)
 804a1b9:	0f b6 00             	movzbl (%eax),%eax
 804a1bc:	0f be c0             	movsbl %al,%eax
 804a1bf:	01 c8                	add    %ecx,%eax
 804a1c1:	89 45 fc             	mov    %eax,-0x4(%ebp)
 804a1c4:	8b 45 08             	mov    0x8(%ebp),%eax
 804a1c7:	0f b6 00             	movzbl (%eax),%eax
 804a1ca:	84 c0                	test   %al,%al
 804a1cc:	75 dc                	jne    804a1aa <hash+0xf>
 804a1ce:	8b 45 fc             	mov    -0x4(%ebp),%eax
 804a1d1:	c9                   	leave  
 804a1d2:	c3                   	ret    

0804a1d3 <check>:
 804a1d3:	55                   	push   %ebp
 804a1d4:	89 e5                	mov    %esp,%ebp
 804a1d6:	83 ec 10             	sub    $0x10,%esp
 804a1d9:	8b 45 08             	mov    0x8(%ebp),%eax
 804a1dc:	c1 e8 1c             	shr    $0x1c,%eax
 804a1df:	85 c0                	test   %eax,%eax
 804a1e1:	75 07                	jne    804a1ea <check+0x17>
 804a1e3:	b8 00 00 00 00       	mov    $0x0,%eax
 804a1e8:	eb 33                	jmp    804a21d <check+0x4a>
 804a1ea:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%ebp)
 804a1f1:	eb 1f                	jmp    804a212 <check+0x3f>
 804a1f3:	8b 45 fc             	mov    -0x4(%ebp),%eax
 804a1f6:	8b 55 08             	mov    0x8(%ebp),%edx
 804a1f9:	89 c1                	mov    %eax,%ecx
 804a1fb:	d3 ea                	shr    %cl,%edx
 804a1fd:	89 d0                	mov    %edx,%eax
 804a1ff:	0f b6 c0             	movzbl %al,%eax
 804a202:	83 f8 0a             	cmp    $0xa,%eax
 804a205:	75 07                	jne    804a20e <check+0x3b>
 804a207:	b8 00 00 00 00       	mov    $0x0,%eax
 804a20c:	eb 0f                	jmp    804a21d <check+0x4a>
 804a20e:	83 45 fc 08          	addl   $0x8,-0x4(%ebp)
 804a212:	83 7d fc 1f          	cmpl   $0x1f,-0x4(%ebp)
 804a216:	7e db                	jle    804a1f3 <check+0x20>
 804a218:	b8 01 00 00 00       	mov    $0x1,%eax
 804a21d:	c9                   	leave  
 804a21e:	c3                   	ret    

0804a21f <gencookie>:
 804a21f:	55                   	push   %ebp
 804a220:	89 e5                	mov    %esp,%ebp
 804a222:	83 ec 18             	sub    $0x18,%esp
 804a225:	ff 75 08             	pushl  0x8(%ebp)
 804a228:	e8 6e ff ff ff       	call   804a19b <hash>
 804a22d:	83 c4 04             	add    $0x4,%esp
 804a230:	83 ec 0c             	sub    $0xc,%esp
 804a233:	50                   	push   %eax
 804a234:	e8 f7 e6 ff ff       	call   8048930 <srand@plt>
 804a239:	83 c4 10             	add    $0x10,%esp
 804a23c:	e8 8f e7 ff ff       	call   80489d0 <rand@plt>
 804a241:	89 45 f4             	mov    %eax,-0xc(%ebp)
 804a244:	83 ec 0c             	sub    $0xc,%esp
 804a247:	ff 75 f4             	pushl  -0xc(%ebp)
 804a24a:	e8 84 ff ff ff       	call   804a1d3 <check>
 804a24f:	83 c4 10             	add    $0x10,%esp
 804a252:	85 c0                	test   %eax,%eax
 804a254:	74 e6                	je     804a23c <gencookie+0x1d>
 804a256:	8b 45 f4             	mov    -0xc(%ebp),%eax
 804a259:	c9                   	leave  
 804a25a:	c3                   	ret    
 804a25b:	66 90                	xchg   %ax,%ax
 804a25d:	66 90                	xchg   %ax,%ax
 804a25f:	90                   	nop

0804a260 <__libc_csu_init>:
 804a260:	55                   	push   %ebp
 804a261:	57                   	push   %edi
 804a262:	56                   	push   %esi
 804a263:	53                   	push   %ebx
 804a264:	e8 37 e8 ff ff       	call   8048aa0 <__x86.get_pc_thunk.bx>
 804a269:	81 c3 97 2d 00 00    	add    $0x2d97,%ebx
 804a26f:	83 ec 0c             	sub    $0xc,%esp
 804a272:	8b 6c 24 20          	mov    0x20(%esp),%ebp
 804a276:	8d b3 0c ff ff ff    	lea    -0xf4(%ebx),%esi
 804a27c:	e8 57 e5 ff ff       	call   80487d8 <_init>
 804a281:	8d 83 08 ff ff ff    	lea    -0xf8(%ebx),%eax
 804a287:	29 c6                	sub    %eax,%esi
 804a289:	c1 fe 02             	sar    $0x2,%esi
 804a28c:	85 f6                	test   %esi,%esi
 804a28e:	74 25                	je     804a2b5 <__libc_csu_init+0x55>
 804a290:	31 ff                	xor    %edi,%edi
 804a292:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 804a298:	83 ec 04             	sub    $0x4,%esp
 804a29b:	ff 74 24 2c          	pushl  0x2c(%esp)
 804a29f:	ff 74 24 2c          	pushl  0x2c(%esp)
 804a2a3:	55                   	push   %ebp
 804a2a4:	ff 94 bb 08 ff ff ff 	call   *-0xf8(%ebx,%edi,4)
 804a2ab:	83 c7 01             	add    $0x1,%edi
 804a2ae:	83 c4 10             	add    $0x10,%esp
 804a2b1:	39 f7                	cmp    %esi,%edi
 804a2b3:	75 e3                	jne    804a298 <__libc_csu_init+0x38>
 804a2b5:	83 c4 0c             	add    $0xc,%esp
 804a2b8:	5b                   	pop    %ebx
 804a2b9:	5e                   	pop    %esi
 804a2ba:	5f                   	pop    %edi
 804a2bb:	5d                   	pop    %ebp
 804a2bc:	c3                   	ret    
 804a2bd:	8d 76 00             	lea    0x0(%esi),%esi

0804a2c0 <__libc_csu_fini>:
 804a2c0:	f3 c3                	repz ret 

Disassembly of section .fini:

0804a2c4 <_fini>:
 804a2c4:	53                   	push   %ebx
 804a2c5:	83 ec 08             	sub    $0x8,%esp
 804a2c8:	e8 d3 e7 ff ff       	call   8048aa0 <__x86.get_pc_thunk.bx>
 804a2cd:	81 c3 33 2d 00 00    	add    $0x2d33,%ebx
 804a2d3:	83 c4 08             	add    $0x8,%esp
 804a2d6:	5b                   	pop    %ebx
 804a2d7:	c3                   	ret    
