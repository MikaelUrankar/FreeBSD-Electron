PORTNAME=	joplin
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9.1
CATEGORIES=	deskutils
MASTER_SITES=	LOCAL/mikael/joplin/:yarn \
		LOCAL/mikael/joplin/:npm
PKGNAMESUFFIX=	-desktop
DISTFILES=	joplin-${DISTVERSION}-yarn-cache.tar.gz:yarn \
		joplin-${DISTVERSION}-npm-cache.tar.gz:npm

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Note taking and to-do application with synchronisation capabilities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	app-builder:devel/app-builder \
		npm:www/npm-node16
LIB_DEPENDS=	libopus.so:audio/opus \
		libpci.so:devel/libpci \
		libvips.so:graphics/vips

USES=		desktop-file-utils electron:18,build gl node:16,build python:3.7+,build xorg

USE_GITHUB=	yes
GH_ACCOUNT=	laurent22

USE_GL=		gl
USE_NODE=	yarn
USE_XORG=	x11 xcb xext xi

BINARY_ALIAS=	python=${PYTHON_CMD}

BUILD_WRKSRC=	${WRKSRC}/packages/app-desktop
APP_OUT_DIR=	linux-${ARCH:S/aarch64/arm64-/:S/amd64//}unpacked

post-extract:
.for dir in app-cli app-clipper app-mobile generator-joplin plugin-repo-cli plugins server
	${RM} -r ${WRKSRC}/packages/${dir}
.endfor

do-build:
# electron-builder is stupid and tries to open ${LOCALBASE}/share/electron19/electron with WRITE priv
# copy ${LOCALBASE}/share/electron18 in WRKDIR
# it's needed for the do-install phase, it's here because of this issue
# https://github.com/MikaelUrankar/signal-desktop/issues/6 (I don't know why it fails though)
	@${RM} -r ${WRKDIR}/electron${ELECTRON_VER_MAJOR}
	@${CP} -pR ${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} ${WRKDIR}/electron${ELECTRON_VER_MAJOR}
	${CHMOD} -R a+w ${WRKDIR}/electron${ELECTRON_VER_MAJOR}

	cd ${WRKSRC}/packages/app-desktop && \
		${SETENV} ${MAKE_ENV} ${YARN_CMD} install

do-install:
	cd ${WRKSRC}/packages/app-desktop && \
		${SETENV} ${MAKE_ENV} ${PACKAGE_ENV} yarn run electron-builder \
			--linux --dir --config.npmRebuild=false \
			--config.electronVersion=${ELECTRON_VER_MAJOR} \
			--config.electronDist=${WRKDIR}/electron${ELECTRON_VER_MAJOR}

	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${BUILD_WRKSRC}/dist/${APP_OUT_DIR} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/packages/app-desktop/dist/linux-unpacked/resources/build/icons/512x512.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/joplin.png
	${INSTALL_DATA} ${FILESDIR}/joplin.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.for f in chromedriver mksnapshot v8_context_snapshot_generator
	${RM} ${STAGEDIR}${DATADIR}/${f}
.endfor
	${RM} -r ${STAGEDIR}${DATADIR}/gen
	${RM} -r ${STAGEDIR}${DATADIR}/node_headers
	${MV} ${STAGEDIR}${DATADIR}/@joplinapp-desktop ${STAGEDIR}${DATADIR}/joplinapp-desktop
	${RLN} ${STAGEDIR}${DATADIR}/joplinapp-desktop ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
