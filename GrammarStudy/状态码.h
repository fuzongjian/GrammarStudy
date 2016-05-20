//
//  状态码.h
//  GrammarStudy
//
//  Created by 陈舒澳 on 16/5/20.
//  Copyright © 2016年 speeda. All rights reserved.
//

#ifndef ____h
#define ____h

/*
 http响应状态码大全
 
 http状态返回代码 1xx（临时响应）
 表示临时响应并需要请求者继续执行操作的状态代码。
 
 http状态返回代码 代码   说明
 100   （继续） 请求者应当继续提出请求。 服务器返回此代码表示已收到请求的第一部分，正在等待其余部分。
 101   （切换协议） 请求者已要求服务器切换协议，服务器已确认并准备切换。
 
 http状态返回代码 2xx （成功）
 表示成功处理了请求的状态代码。
 
 http状态返回代码 代码   说明
 200   （成功）  服务器已成功处理了请求。 通常，这表示服务器提供了请求的网页。
 201   （已创建）  请求成功并且服务器创建了新的资源。
 202   （已接受）  服务器已接受请求，但尚未处理。
 203   （非授权信息）  服务器已成功处理了请求，但返回的信息可能来自另一来源。
 204   （无内容）  服务器成功处理了请求，但没有返回任何内容。
 205   （重置内容） 服务器成功处理了请求，但没有返回任何内容。
 206   （部分内容）  服务器成功处理了部分 GET 请求。
 
 http状态返回代码 3xx （重定向）
 表示要完成请求，需要进一步操作。 通常，这些状态代码用来重定向。
 
 http状态返回代码 代码   说明
 300   （多种选择）  针对请求，服务器可执行多种操作。 服务器可根据请求者 (user agent) 选择一项操作，或提供操作列表供请求者选择。
 301   （永久移动）  请求的网页已永久移动到新位置。 服务器返回此响应（对 GET 或 HEAD 请求的响应）时，会自动将请求者转到新位置。
 302   （临时移动）  服务器目前从不同位置的网页响应请求，但请求者应继续使用原有位置来进行以后的请求。
 303   （查看其他位置） 请求者应当对不同的位置使用单独的 GET 请求来检索响应时，服务器返回此代码。
 
 304   （未修改） 自从上次请求后，请求的网页未修改过。 服务器返回此响应时，不会返回网页内容。
 305   （使用代理） 请求者只能使用代理访问请求的网页。 如果服务器返回此响应，还表示请求者应使用代理。
 307   （临时重定向）  服务器目前从不同位置的网页响应请求，但请求者应继续使用原有位置来进行以后的请求。
 http状态返回代码 4xx（请求错误）
 这些状态代码表示请求可能出错，妨碍了服务器的处理。
 
 http状态返回代码 代码   说明
 400   （错误请求） 服务器不理解请求的语法。
 401   （未授权） 请求要求身份验证。 对于需要登录的网页，服务器可能返回此响应。
 403   （禁止） 服务器拒绝请求。
 404   （未找到） 服务器找不到请求的网页。
 405   （方法禁用） 禁用请求中指定的方法。
 406   （不接受） 无法使用请求的内容特性响应请求的网页。
 407   （需要代理授权） 此状态代码与 401（未授权）类似，但指定请求者应当授权使用代理。
 408   （请求超时）  服务器等候请求时发生超时。
 409   （冲突）  服务器在完成请求时发生冲突。 服务器必须在响应中包含有关冲突的信息。
 410   （已删除）  如果请求的资源已永久删除，服务器就会返回此响应。
 411   （需要有效长度） 服务器不接受不含有效内容长度标头字段的请求。
 412   （未满足前提条件） 服务器未满足请求者在请求中设置的其中一个前提条件。
 413   （请求实体过大） 服务器无法处理请求，因为请求实体过大，超出服务器的处理能力。
 414   （请求的 URI 过长） 请求的 URI（通常为网址）过长，服务器无法处理。
 415   （不支持的媒体类型） 请求的格式不受请求页面的支持。
 416   （请求范围不符合要求） 如果页面无法提供请求的范围，则服务器会返回此状态代码。
 417   （未满足期望值） 服务器未满足"期望"请求标头字段的要求。
 
 http状态返回代码 5xx（服务器错误）
 这些状态代码表示服务器在尝试处理请求时发生内部错误。 这些错误可能是服务器本身的错误，而不是请求出错。
 
 http状态返回代码 代码   说明
 500   （服务器内部错误）  服务器遇到错误，无法完成请求。
 501   （尚未实施） 服务器不具备完成请求的功能。 例如，服务器无法识别请求方法时可能会返回此代码。
 502   （错误网关） 服务器作为网关或代理，从上游服务器收到无效响应。
 503   （服务不可用） 服务器目前无法使用（由于超载或停机维护）。 通常，这只是暂时状态。
 504   （网关超时）  服务器作为网关或代理，但是没有及时从上游服务器收到请求。
 505   （HTTP 版本不受支持） 服务器不支持请求中所用的 HTTP 协议版本。
 
 一些常见的http状态返回代码为：
 200 - 服务器成功返回网页
 404 - 请求的网页不存在
 503 - 服务不可用
 
 
 NSError codes in the Cocoa error domain.
 
 enum {
 NSFileNoSuchFileError = 4,
 NSFileLockingError = 255,
 NSFileReadUnknownError = 256,
 NSFileReadNoPermissionError = 257,
 NSFileReadInvalidFileNameError = 258,
 NSFileReadCorruptFileError = 259,
 NSFileReadNoSuchFileError = 260,
 NSFileReadInapplicableStringEncodingError = 261,
 NSFileReadUnsupportedSchemeError = 262,
 NSFileReadTooLargeError = 263,
 NSFileReadUnknownStringEncodingError = 264,
 NSFileWriteUnknownError = 512,
 NSFileWriteNoPermissionError = 513,
 NSFileWriteInvalidFileNameError = 514,
 NSFileWriteInapplicableStringEncodingError = 517,
 NSFileWriteUnsupportedSchemeError = 518,
 NSFileWriteOutOfSpaceError = 640,
 NSFileWriteVolumeReadOnlyError = 642m
 NSKeyValueValidationError = 1024,
 NSFormattingError = 2048,
 NSUserCancelledError = 3072,
 
 NSFileErrorMinimum = 0,
 NSFileErrorMaximum = 1023,
 NSValidationErrorMinimum = 1024,
 NSValidationErrorMaximum = 2047,
 NSFormattingErrorMinimum = 2048,
 NSFormattingErrorMaximum = 2559,
 
 NSPropertyListReadCorruptError = 3840,
 NSPropertyListReadUnknownVersionError = 3841,
 NSPropertyListReadStreamError = 3842,
 NSPropertyListWriteStreamError = 3851,
 NSPropertyListErrorMinimum = 3840,
 NSPropertyListErrorMaximum = 4095
 
 NSExecutableErrorMinimum = 3584,
 NSExecutableNotLoadableError = 3584,
 NSExecutableArchitectureMismatchError = 3585,
 NSExecutableRuntimeMismatchError = 3586,
 NSExecutableLoadError = 3587,
 NSExecutableLinkError = 3588,
 NSExecutableErrorMaximum = 3839,
 
 }
 URL Loading System Error Codes
 
 
 
 NSURLErrorDomain
 
 These values are returned as the error code property of an NSError object with the domain “NSURLErrorDomain”.
 typedef enum
 {
 NSURLErrorUnknown = -1,
 NSURLErrorCancelled = -999,
 NSURLErrorBadURL = -1000,
 NSURLErrorTimedOut = -1001,
 NSURLErrorUnsupportedURL = -1002,
 NSURLErrorCannotFindHost = -1003,
 NSURLErrorCannotConnectToHost = -1004,
 NSURLErrorDataLengthExceedsMaximum = -1103,
 NSURLErrorNetworkConnectionLost = -1005,
 NSURLErrorDNSLookupFailed = -1006,
 NSURLErrorHTTPTooManyRedirects = -1007,
 NSURLErrorResourceUnavailable = -1008,
 NSURLErrorNotConnectedToInternet = -1009,
 NSURLErrorRedirectToNonExistentLocation = -1010,
 NSURLErrorBadServerResponse = -1011,
 NSURLErrorUserCancelledAuthentication = -1012,
 NSURLErrorUserAuthenticationRequired = -1013,
 NSURLErrorZeroByteResource = -1014,
 NSURLErrorCannotDecodeRawData = -1015,
 NSURLErrorCannotDecodeContentData = -1016,
 NSURLErrorCannotParseResponse = -1017,
 NSURLErrorFileDoesNotExist = -1100,
 NSURLErrorFileIsDirectory = -1101,
 NSURLErrorNoPermissionsToReadFile = -1102,
 NSURLErrorSecureConnectionFailed = -1200,
 NSURLErrorServerCertificateHasBadDate = -1201,
 NSURLErrorServerCertificateUntrusted = -1202,
 NSURLErrorServerCertificateHasUnknownRoot = -1203,
 NSURLErrorServerCertificateNotYetValid = -1204,
 NSURLErrorClientCertificateRejected = -1205,
 NSURLErrorClientCertificateRequired = -1206,
 NSURLErrorCannotLoadFromNetwork = -2000,
 NSURLErrorCannotCreateFile = -3000,
 NSURLErrorCannotOpenFile = -3001,
 NSURLErrorCannotCloseFile = -3002,
 NSURLErrorCannotWriteToFile = -3003,
 NSURLErrorCannotRemoveFile = -3004,
 NSURLErrorCannotMoveFile = -3005,
 NSURLErrorDownloadDecodingFailedMidStream = -3006,
 NSURLErrorDownloadDecodingFailedToComplete = -3007
 }
 
 

 */
#endif /* ____h */
