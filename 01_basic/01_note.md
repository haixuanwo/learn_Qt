<!--
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-07-06 14:49:22
 * @LastEditors: Clark
 * @LastEditTime: 2024-07-06 16:20:29
 * @Description: file content
-->


# QVariant
在Qt中，QVariant 是一个非常强大的类，它可以存储和处理多种不同类型的数据。QVariant 的主要功能是作为一个通用的数据容器，可以容纳几乎所有常见的Qt数据类型，如 int、QString、QList、QMap 等。这使得 QVariant 在需要处理多种数据类型的场景中非常有用，例如在模型/视图架构中传递数据或在不同组件之间传递参数。

# QSplitter
是 Qt 框架中的一个控件，主要功能是将窗口分割成多个可调整大小的区域。用户可以通过拖动分隔条来调整各个区域的大小，这在设计复杂的用户界面时非常有用，允许用户自定义界面元素的布局。

以下 QSplitter 的主要功能和作用：

分割窗口：允许将窗口分割成两个或多个部分，每个部分可以包含不同的控件。
动态调整：用户可以通过拖动分隔条来动态调整各部分的大小。
布局管理：QSplitter 可以作为布局管理器使用，动态管理子控件的大小和位置。

===========================================================================

QGridLayout
QFrame
QLineEdit

# QPushButton
setText, setIcon, setShortcut, setCheckable, setChecked, setEnabled, setVisible, setDisabled, setFlat, setMenu, setToolTip, setWhatsThis, setFont, setCursor, setFixedSize, setFixedWidth, setFixedHeight, setMinimumSize, setMinimumWidth, setMinimumHeight, setMaximumSize, setMaximumWidth, setMaximumHeight, setSizePolicy, setLayout, setMargin, setSpacing, setContentsMargins, setFrameStyle, setLineWidth, setMidLineWidth, setFrameShadow, setFrameShape, setMidLineColor, setFrameRect, setMask, setMasked, setMouseTracking, setObjectName, setProperty, setStyleSheet, setToolTipDuration, setWhatsThisVisible, setWindowFlags, setWindowTitle, setWindowIcon, setWindowModality, setWindowOpacity, setWindowState, setWindowFilePath, setWindowModified, setWindowRole, setWindowIconText, setWindowModified

# 控件
QLabel
QLineEdit
QTextEdit
QPlainTextEdit
QSpinBox
QDoubleSpinBox
QComboBox
QProgressBar
QSlider
QScrollBar
QDial
QDateEdit
QTimeEdit
QDateTimeEdit
QCalendarWidget
QFontComboBox
QToolButton
QCommandLinkButton
QPushButton
QRadioButton
QCheckBox
QGroupBox
QTabWidget
QTableView
QTreeWidget
QTreeWidgetItem
QHeaderView
QScrollBar
QGraphicsView
QGraphicsScene
QGraphicsItem
QLCDNumber

# 布局管理器
QGridLayout
QFormLayout
QBoxLayout
QStackedLayout
QSpacerItem
QGraphicsLayout

QPixmap
QIcon
QImage
QPainter
QPen
QBrush
QRect
QPoint
QSize

QMouseEvent
QKeyEvent
QWheelEvent
QTouchEvent
QDragEnterEvent
QPaintEvent

QColor
QFont
QPalette: 管理和控制小部件的颜色设置

# QFrame
是一个用于提供各种边框和框架效果的基础类。

主要功能和作用包括：
- 提供不同的边框样式：可以设置如线框、阴影等边框效果。
- 作为容器：能够容纳其他控件，为其提供一个特定的显示区域和外观。
- 背景设置：可以设置背景颜色、背景图片等。
- 形状定制：通过设置不同的属性，可以实现矩形、圆形等各种形状的框架。
QFrame 有多种预定义的样式，例如 QFrame::Panel（平面面板）、QFrame::Box（立体框）、QFrame::HLine（水平线条）、QFrame::VLine（垂直线条）等。

# QMessageBox
Save, Open, Warning, Information, Question, Critical, AboutQt, About, Yes, No, Cancel, Ok, Apply, Reset, Close, Help,

QFileDialog
QColorDialog
QFontDialog
QProgressDialog

# QInputDialog
getText, getInt, getDouble, getItem, getMultiLineText, getColor, getFont

# QToolBox

# tr
是一个宏，用于将字符串从源代码翻译成目标语言的文本。它是 Qt 国际化（i18n）系统的一部分，允许开发者轻松地实现应用程序的多语言支持。

tr 的作用主要包括以下几点：
- 简化翻译过程：使用 tr 宏可以自动将字符串标记为需要翻译的文本，这样开发者不需要手动处理字符串的翻译。
- 保持源代码整洁：将字符串翻译工作分离到外部文件中，使得源代码更加简洁和易于阅读。
- 支持多种语言：Qt 的国际化支持可以自动检测系统语言设置，并使用相应的翻译。
- 避免硬编码：使用 tr 宏可以避免在代码中直接使用硬编码的字符串，这有助于减少因语言更改而需要修改代码的情况。
- 支持上下文相关的翻译：tr 宏允许传递额外的参数，这些参数可以作为上下文信息，帮助翻译者更准确地翻译字符串

# QPainter
用于在各种绘图设备上进行绘制的类，它的主要功能和作用非常广泛，以下是一些核心的要点：

主要功能：
- 绘制基本图形：QPainter 可以绘制点、线、矩形、椭圆、圆弧、多边形等基本图形。
- 绘制文本：支持在绘图设备上绘制文本，包括使用不同的字体、样式和大小。
- 绘制图像：能够绘制 QImage、QPixmap 和 QBitmap 对象，即可以加载并显示图片。
- 坐标变换：提供平移、旋转、缩放等坐标变换功能，允许在绘制之前改变坐标系统。
- 裁剪和视口控制：可以设置裁剪区域，只绘制指定区域内的内容，还可以控制绘制的视口和窗口。
- 抗锯齿和渲染提示：通过渲染提示，如 QPainter::Antialiasing，可以改善绘图质量，减少锯齿边缘。
- 双缓冲技术：通过在内存中绘制，然后一次性将结果输出到屏幕上，减少闪烁并提高绘图效率。
- 画笔和画刷：使用 QPen 和 QBrush 对象来设置线条和填充的样式、颜色和宽度。

作用：
- 图形用户界面绘制：在 QWidget 的子类中，QPainter 用于绘制图形用户界面元素。
- 游戏和动画：在游戏开发和动画制作中，QPainter 可用于绘制动态元素和场景。
- 数据可视化：在数据可视化应用中，QPainter 可用于绘制图表、图形和其他数据表示。
- 图像处理：QPainter 可以与 QImage 和 QPixmap 结合使用，进行图像处理和图像合成。
- 自定义控件：在开发自定义控件时，QPainter 允许开发者绘制独特的界面元素。
- 打印：QPainter 也支持在打印机上进行绘制，实现打印功能。
QPainter 的使用通常与事件处理相结合，特别是在 QWidget 的 paintEvent 方法中，这是进行绘制操作的地方。由于 QPainter 是基于状态的，使用时要注意设置正确的状态（如画笔、画刷、变换等）并在绘制完成后恢复到原始状态。


QIcon           图标
QMenu           菜单栏
QAction         菜单项
QToolBar        工具栏
QStatusBar      状态栏
QDockWidget     停靠窗口
QFontComboBox   字体选择框
QToolButton     工具按钮
QActionGroup    动作组



