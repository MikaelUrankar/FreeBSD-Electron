PORTNAME=	teams
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.23
CATEGORIES=	net-im

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Unofficial Microsoft Teams client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	app-builder:devel/app-builder

USES=		desktop-file-utils electron:15 gnome localbase:ldflags \
		node:16,build python:build

USE_GITHUB=	yes
GH_ACCOUNT=	IsmaelMartinez
GH_PROJECT=	teams-for-linux

SUB_FILES=	${PORTNAME}

PORTDOCS=	HISTORY.md KNOWN_ISSUES.md README.md

OPTIONS_DEFINE=	DOCS

USE_NODE=	yarn
USE_ELECTRON=	prefetch extract prebuild build:builder

PREFETCH_TIMESTAMP=	1644902604

post-patch:
	${REINPLACE_CMD} -e 's/OS=="linux"/& or OS=="freebsd"/' \
		${WRKSRC}/node_modules/spellchecker/binding.gyp
	${REINPLACE_CMD} -e 's/needflag = NULL/needflag = FLAG_NULL/' \
		${WRKSRC}/node_modules/spellchecker/vendor/hunspell/src/hunspell/affentry.hxx

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
.for size in 16 24 32 48 64 96 128 256 512 1024
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps
	${INSTALL_DATA} ${WRKSRC}/build/icons/${size}x${size}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/${PORTNAME}.png
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/dist/linux-unpacked && \
		${COPYTREE_SHARE} resources ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
